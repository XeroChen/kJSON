#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include <stdio.h>
#include "kjson.h"
#include "test_utils.h"

static void test_simple_object(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{\"key\": \"value\"}";
    
    expected_event_t expected[] = {
        { EVENT_OBJECT_START, NULL },
        { EVENT_KEY, "key" },
        { EVENT_VALUE, "value" },
        { EVENT_OBJECT_END, NULL }
    };
    
    test_context_t ctx = { expected, 4, 0 };
    
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 4);
    
    kjson_parser_destroy(parser);
}

static void test_nested_object(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{\"a\": {\"b\": 1}}";
    
    expected_event_t expected[] = {
        { EVENT_OBJECT_START, NULL },
        { EVENT_KEY, "a" },
        { EVENT_OBJECT_START, NULL },
        { EVENT_KEY, "b" },
        { EVENT_VALUE, "1" },
        { EVENT_OBJECT_END, NULL },
        { EVENT_OBJECT_END, NULL }
    };
    
    test_context_t ctx = { expected, 7, 0 };
    
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 7);
    
    kjson_parser_destroy(parser);
}

static void test_array(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[1, 2, 3]";
    
    expected_event_t expected[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "1" },
        { EVENT_VALUE, "2" },
        { EVENT_VALUE, "3" },
        { EVENT_ARRAY_END, NULL }
    };
    
    test_context_t ctx = { expected, 5, 0 };
    
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 5);
    
    kjson_parser_destroy(parser);
}

static void test_mixed(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{\"arr\": [true, false, null]}";
    
    expected_event_t expected[] = {
        { EVENT_OBJECT_START, NULL },
        { EVENT_KEY, "arr" },
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "true" },
        { EVENT_VALUE, "false" },
        { EVENT_VALUE, "null" },
        { EVENT_ARRAY_END, NULL },
        { EVENT_OBJECT_END, NULL }
    };
    
    test_context_t ctx = { expected, 8, 0 };
    
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 8);
    
    kjson_parser_destroy(parser);
}

static void test_loose_types(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[0xFF, NaN, Inf, .123]";
    
    expected_event_t expected[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "0xFF" },
        { EVENT_VALUE, "NaN" },
        { EVENT_VALUE, "Inf" },
        { EVENT_VALUE, ".123" },
        { EVENT_ARRAY_END, NULL }
    };
    
    test_context_t ctx = { expected, 6, 0 };
    
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 6);
    
    kjson_parser_destroy(parser);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_simple_object),
        cmocka_unit_test(test_nested_object),
        cmocka_unit_test(test_array),
        cmocka_unit_test(test_mixed),
        cmocka_unit_test(test_loose_types),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
