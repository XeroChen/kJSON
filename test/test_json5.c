#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <string.h>
#include <stdio.h>
#include "kjson.h"

static int object_start_count = 0;
static int object_end_count = 0;
static int array_start_count = 0;
static int array_end_count = 0;
static int key_count = 0;
static int value_count = 0;

static void reset_counts() {
    object_start_count = 0;
    object_end_count = 0;
    array_start_count = 0;
    array_end_count = 0;
    key_count = 0;
    value_count = 0;
}

static void on_object_start(size_t offset, void* user_data) {
    object_start_count++;
}

static void on_object_end(size_t offset, void* user_data) {
    object_end_count++;
}

static void on_array_start(size_t offset, void* user_data) {
    array_start_count++;
}

static void on_array_end(size_t offset, void* user_data) {
    array_end_count++;
}

static void on_key(const char* data, size_t length, void* user_data) {
    key_count++;
}

static void on_value(const char* data, size_t length, void* user_data) {
    value_count++;
}

static kjson_event_handlers_t handlers = {
    .on_object_start = on_object_start,
    .on_object_end = on_object_end,
    .on_array_start = on_array_start,
    .on_array_end = on_array_end,
    .on_key = on_key,
    .on_value = on_value
};

static void test_json5_comments(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{ // This is a comment\n"
                       "  \"key\": /* Multi-line \n comment */ \"value\" }";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(object_start_count, 1);
    assert_int_equal(key_count, 1);
    assert_int_equal(value_count, 1);
    
    kjson_parser_destroy(parser);
}

static void test_json5_trailing_comma(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[1, 2, 3, ]";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(array_start_count, 1);
    assert_int_equal(value_count, 3);
    
    kjson_parser_destroy(parser);
}

static void test_json5_unquoted_keys(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{ key: \"value\", $var: 123, _underscore: true }";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(object_start_count, 1);
    assert_int_equal(key_count, 3);
    assert_int_equal(value_count, 3);
    
    kjson_parser_destroy(parser);
}

static void test_json5_single_quotes(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{ 'key': 'value' }";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(object_start_count, 1);
    assert_int_equal(key_count, 1);
    assert_int_equal(value_count, 1);
    
    kjson_parser_destroy(parser);
}

static void test_json5_simple_comment(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "/* comment */ \"value\"";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    if (status != KJSON_OK) {
        printf("Parse failed with status: %d\n", status);
    }
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(value_count, 1);
    
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
