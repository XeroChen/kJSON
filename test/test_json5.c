#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <string.h>
#include <stdio.h>
#include "kjson.h"
#include "test_utils.h"

static void test_json5_comments(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{ // This is a comment\n"
                       "  \"key\": /* Multi-line \n comment */ \"value\" }";
    
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

static void test_json5_trailing_comma(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[1, 2, 3, ]";
    
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

static void test_json5_unquoted_keys(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{ key: \"value\", $var: 123, _underscore: true }";
    
    expected_event_t expected[] = {
        { EVENT_OBJECT_START, NULL },
        { EVENT_KEY, "key" },
        { EVENT_VALUE, "value" },
        { EVENT_KEY, "$var" },
        { EVENT_VALUE, "123" },
        { EVENT_KEY, "_underscore" },
        { EVENT_VALUE, "true" },
        { EVENT_OBJECT_END, NULL }
    };
    
    test_context_t ctx = { expected, 8, 0 };
    
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 8);
    
    kjson_parser_destroy(parser);
}

static void test_json5_single_quotes(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{ 'key': 'value' }";
    
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

static void test_json5_simple_comment(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "/* comment */ \"value\"";
    
    expected_event_t expected[] = {
        { EVENT_VALUE, "value" }
    };
    
    test_context_t ctx = { expected, 1, 0 };
    
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    
    if (status != KJSON_OK) {
        printf("Parse failed with status: %d\n", status);
    }
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 1);
    
    kjson_parser_destroy(parser);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_json5_simple_comment),
        cmocka_unit_test(test_json5_comments),
        cmocka_unit_test(test_json5_trailing_comma),
        cmocka_unit_test(test_json5_unquoted_keys),
        cmocka_unit_test(test_json5_single_quotes),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
