/*
 * test_max_depth.c
 *
 * Tests for Issue 5: strict enforcement of kjson_config_t.max_depth during
 * parsing.  Covers:
 *
 *  - Documents that fit within the configured depth succeed with KJSON_OK.
 *  - Documents that exceed the configured depth fail with
 *    KJSON_ERROR_MAX_DEPTH_EXCEEDED (not KJSON_ERROR_INVALID_JSON).
 *  - The boundary: a document at exactly max_depth succeeds; one at
 *    max_depth + 1 fails.
 *  - Both object and array nesting are enforced independently.
 *  - Mixed object/array nesting counts correctly.
 *  - max_depth = 0 rejects any object or array at the top level.
 *  - max_depth = 1 accepts a flat object/array but rejects any nesting.
 *  - The default config (max_depth = 32) accepts 32 levels of nesting.
 *  - After a depth-exceeded failure, kjson_parser_reset() restores the
 *    parser so it can successfully parse a shallower document.
 *  - A top-level scalar (no nesting) is unaffected by max_depth >= 1.
 */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "kjson.h"
#include "test_utils.h"

/* -------------------------------------------------------------------------
 * Helpers
 * -------------------------------------------------------------------------*/

/* Build a JSON string with N levels of nested objects: {"a":{"a":{...}}}
 * ending with a leaf value.  Caller must free the returned buffer. */
static char* make_nested_objects(size_t depth) {
    /* Each level: {"a": at start, } at end; leaf: 1 */
    size_t open_len = strlen("{\"a\":");  /* 5 chars */
    size_t close_len = 1;               /* } */
    size_t total = depth * (open_len + close_len) + 1 /* leaf */ + 1 /* NUL */;
    char* buf = (char*)malloc(total);
    if (!buf) return NULL;

    char* p = buf;
    for (size_t i = 0; i < depth; i++) {
        memcpy(p, "{\"a\":", open_len);
        p += open_len;
    }
    *p++ = '1';
    for (size_t i = 0; i < depth; i++) {
        *p++ = '}';
    }
    *p = '\0';
    return buf;
}

/* Build a JSON string with N levels of nested arrays: [[...[1]...]]
 * Caller must free the returned buffer. */
static char* make_nested_arrays(size_t depth) {
    size_t total = depth * 2 + 1 /* leaf */ + 1 /* NUL */;
    char* buf = (char*)malloc(total);
    if (!buf) return NULL;

    char* p = buf;
    for (size_t i = 0; i < depth; i++) *p++ = '[';
    *p++ = '1';
    for (size_t i = 0; i < depth; i++) *p++ = ']';
    *p = '\0';
    return buf;
}

/* -------------------------------------------------------------------------
 * Tests: correct error code
 * -------------------------------------------------------------------------*/

/* Exceeding the limit must return the specific depth error, not the generic
   invalid-JSON error. */
static void test_error_code_is_max_depth_exceeded(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 1, .max_string_length = 1024, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    /* {"a":{"b":1}} has depth 2, exceeds max_depth=1 */
    const char* json = "{\"a\":{\"b\":1}}";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &noop, NULL);

    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);
    kjson_parser_destroy(parser);
}

/* -------------------------------------------------------------------------
 * Tests: max_depth = 0
 * -------------------------------------------------------------------------*/

/* Any object at the top level must fail with max_depth=0. */
static void test_depth0_rejects_object(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 0, .max_string_length = 1024, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    kjson_status_t status = kjson_parse(parser, "{}", 2, &noop, NULL);
    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);
    kjson_parser_destroy(parser);
}

/* Any array at the top level must fail with max_depth=0. */
static void test_depth0_rejects_array(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 0, .max_string_length = 1024, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    kjson_status_t status = kjson_parse(parser, "[]", 2, &noop, NULL);
    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);
    kjson_parser_destroy(parser);
}

/* -------------------------------------------------------------------------
 * Tests: max_depth = 1
 * -------------------------------------------------------------------------*/

/* A flat empty object is exactly at depth 1 — must succeed. */
static void test_depth1_accepts_flat_object(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 1, .max_string_length = 1024, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);

    expected_event_t exp[] = {
        { EVENT_OBJECT_START, NULL },
        { EVENT_KEY,          "k"  },
        { EVENT_VALUE,        "v"  },
        { EVENT_OBJECT_END,   NULL }
    };
    test_context_t ctx = { exp, 4, 0 };

    kjson_status_t status = kjson_parse(parser, "{\"k\":\"v\"}", strlen("{\"k\":\"v\"}"),
                                        &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 4);
    kjson_parser_destroy(parser);
}

/* A flat array is exactly at depth 1 — must succeed. */
static void test_depth1_accepts_flat_array(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 1, .max_string_length = 1024, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);

    expected_event_t exp[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE,       "1"  },
        { EVENT_VALUE,       "2"  },
        { EVENT_ARRAY_END,   NULL }
    };
    test_context_t ctx = { exp, 4, 0 };

    kjson_status_t status = kjson_parse(parser, "[1,2]", 5, &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 4);
    kjson_parser_destroy(parser);
}

/* Nested object inside an object is depth 2 — must fail with max_depth=1. */
static void test_depth1_rejects_nested_object(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 1, .max_string_length = 1024, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    kjson_status_t status = kjson_parse(parser, "{\"a\":{}}", strlen("{\"a\":{}}"), &noop, NULL);
    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);
    kjson_parser_destroy(parser);
}

/* Nested array inside an array is depth 2 — must fail with max_depth=1. */
static void test_depth1_rejects_nested_array(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 1, .max_string_length = 1024, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    kjson_status_t status = kjson_parse(parser, "[[]]", 4, &noop, NULL);
    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);
    kjson_parser_destroy(parser);
}

/* -------------------------------------------------------------------------
 * Tests: boundary — exactly at max_depth vs. one over
 * -------------------------------------------------------------------------*/

/* A document nested exactly max_depth levels must succeed. */
static void test_boundary_at_max_depth_succeeds(void **state) {
    (void)state;
    const size_t depth = 5;
    kjson_config_t cfg = { .max_depth = depth, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    char* json = make_nested_objects(depth);
    assert_non_null(json);

    kjson_status_t status = kjson_parse(parser, json, strlen(json), &noop, NULL);
    assert_int_equal(status, KJSON_OK);

    free(json);
    kjson_parser_destroy(parser);
}

/* A document nested one level beyond max_depth must fail. */
static void test_boundary_one_over_max_depth_fails(void **state) {
    (void)state;
    const size_t depth = 5;
    kjson_config_t cfg = { .max_depth = depth, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    char* json = make_nested_objects(depth + 1);
    assert_non_null(json);

    kjson_status_t status = kjson_parse(parser, json, strlen(json), &noop, NULL);
    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);

    free(json);
    kjson_parser_destroy(parser);
}

/* Same boundary test using nested arrays. */
static void test_boundary_arrays_at_max_depth_succeeds(void **state) {
    (void)state;
    const size_t depth = 4;
    kjson_config_t cfg = { .max_depth = depth, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    char* json = make_nested_arrays(depth);
    assert_non_null(json);

    kjson_status_t status = kjson_parse(parser, json, strlen(json), &noop, NULL);
    assert_int_equal(status, KJSON_OK);

    free(json);
    kjson_parser_destroy(parser);
}

static void test_boundary_arrays_one_over_fails(void **state) {
    (void)state;
    const size_t depth = 4;
    kjson_config_t cfg = { .max_depth = depth, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    char* json = make_nested_arrays(depth + 1);
    assert_non_null(json);

    kjson_status_t status = kjson_parse(parser, json, strlen(json), &noop, NULL);
    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);

    free(json);
    kjson_parser_destroy(parser);
}

/* -------------------------------------------------------------------------
 * Tests: mixed object/array nesting
 * -------------------------------------------------------------------------*/

/* Mixed nesting: depth counts objects and arrays together. */
static void test_mixed_nesting_counts_both(void **state) {
    (void)state;
    /* {[{[1]}]} — 4 levels deep */
    const char* json4 = "{\"a\":[{\"b\":[1]}]}";
    const char* json5 = "{\"a\":[{\"b\":[{\"c\":1}]}]}";

    kjson_config_t cfg4 = { .max_depth = 4, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* p4 = kjson_parser_create(&cfg4);
    kjson_event_handlers_t noop = {0};
    assert_int_equal(kjson_parse(p4, json4, strlen(json4), &noop, NULL), KJSON_OK);
    kjson_parser_destroy(p4);

    kjson_config_t cfg3 = { .max_depth = 3, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* p3 = kjson_parser_create(&cfg3);
    assert_int_equal(kjson_parse(p3, json4, strlen(json4), &noop, NULL),
                     KJSON_ERROR_MAX_DEPTH_EXCEEDED);
    kjson_parser_destroy(p3);

    kjson_config_t cfg5 = { .max_depth = 5, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* p5 = kjson_parser_create(&cfg5);
    assert_int_equal(kjson_parse(p5, json5, strlen(json5), &noop, NULL), KJSON_OK);
    kjson_parser_destroy(p5);
}

/* -------------------------------------------------------------------------
 * Tests: default config (max_depth = 32)
 * -------------------------------------------------------------------------*/

/* The default config must handle 32 levels of nesting. */
static void test_default_config_accepts_32_levels(void **state) {
    (void)state;
    kjson_parser_t* parser = kjson_parser_create(NULL); /* default: max_depth=32 */
    kjson_event_handlers_t noop = {0};

    char* json = make_nested_objects(32);
    assert_non_null(json);

    kjson_status_t status = kjson_parse(parser, json, strlen(json), &noop, NULL);
    assert_int_equal(status, KJSON_OK);

    free(json);
    kjson_parser_destroy(parser);
}

/* The default config must reject 33 levels. */
static void test_default_config_rejects_33_levels(void **state) {
    (void)state;
    kjson_parser_t* parser = kjson_parser_create(NULL);
    kjson_event_handlers_t noop = {0};

    char* json = make_nested_objects(33);
    assert_non_null(json);

    kjson_status_t status = kjson_parse(parser, json, strlen(json), &noop, NULL);
    assert_int_equal(status, KJSON_ERROR_MAX_DEPTH_EXCEEDED);

    free(json);
    kjson_parser_destroy(parser);
}

/* -------------------------------------------------------------------------
 * Tests: reset after depth-exceeded
 * -------------------------------------------------------------------------*/

/* After a depth-exceeded failure, reset must allow a shallower parse to
   succeed with KJSON_OK. */
static void test_reset_after_depth_exceeded(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 2, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);
    kjson_event_handlers_t noop = {0};

    /* Fails: 3 levels */
    const char* deep = "{\"a\":{\"b\":{\"c\":1}}}";
    assert_int_equal(kjson_parse(parser, deep, strlen(deep), &noop, NULL),
                     KJSON_ERROR_MAX_DEPTH_EXCEEDED);

    /* Reset, then parse something valid at depth 2 */
    kjson_parser_reset(parser);

    expected_event_t exp[] = {
        { EVENT_OBJECT_START, NULL  },
        { EVENT_KEY,          "a"   },
        { EVENT_OBJECT_START, NULL  },
        { EVENT_KEY,          "b"   },
        { EVENT_VALUE,        "1"   },
        { EVENT_OBJECT_END,   NULL  },
        { EVENT_OBJECT_END,   NULL  }
    };
    test_context_t ctx = { exp, 7, 0 };
    const char* shallow = "{\"a\":{\"b\":1}}";
    assert_int_equal(kjson_parse(parser, shallow, strlen(shallow), &test_handlers, &ctx),
                     KJSON_OK);
    assert_int_equal(ctx.current, 7);

    kjson_parser_destroy(parser);
}

/* -------------------------------------------------------------------------
 * Tests: top-level scalar is unaffected by max_depth
 * -------------------------------------------------------------------------*/

/* A scalar value has no nesting — it must succeed even with max_depth=0. */
static void test_scalar_unaffected_by_max_depth(void **state) {
    (void)state;
    kjson_config_t cfg = { .max_depth = 0, .max_string_length = 0, .allow_json5 = 1 };
    kjson_parser_t* parser = kjson_parser_create(&cfg);

    expected_event_t exp[] = { { EVENT_VALUE, "42" } };
    test_context_t ctx = { exp, 1, 0 };
    assert_int_equal(kjson_parse(parser, "42", 2, &test_handlers, &ctx), KJSON_OK);
    assert_int_equal(ctx.current, 1);

    kjson_parser_destroy(parser);
}

/* -------------------------------------------------------------------------
 * main
 * -------------------------------------------------------------------------*/
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_error_code_is_max_depth_exceeded),

        cmocka_unit_test(test_depth0_rejects_object),
        cmocka_unit_test(test_depth0_rejects_array),

        cmocka_unit_test(test_depth1_accepts_flat_object),
        cmocka_unit_test(test_depth1_accepts_flat_array),
        cmocka_unit_test(test_depth1_rejects_nested_object),
        cmocka_unit_test(test_depth1_rejects_nested_array),

        cmocka_unit_test(test_boundary_at_max_depth_succeeds),
        cmocka_unit_test(test_boundary_one_over_max_depth_fails),
        cmocka_unit_test(test_boundary_arrays_at_max_depth_succeeds),
        cmocka_unit_test(test_boundary_arrays_one_over_fails),

        cmocka_unit_test(test_mixed_nesting_counts_both),

        cmocka_unit_test(test_default_config_accepts_32_levels),
        cmocka_unit_test(test_default_config_rejects_33_levels),

        cmocka_unit_test(test_reset_after_depth_exceeded),

        cmocka_unit_test(test_scalar_unaffected_by_max_depth),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
