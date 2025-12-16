#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
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
    printf("on_object_end called\n");
    object_end_count++;
}

static void on_array_start(size_t offset, void* user_data) {
    array_start_count++;
}

static void on_array_end(size_t offset, void* user_data) {
    array_end_count++;
}

static void on_key(const char* key, size_t key_length, void* user_data) {
    key_count++;
    // printf("Key: %.*s\n", (int)key_length, key);
}

static void on_value(const char* value, size_t value_length, void* user_data) {
    printf("on_value called: %.*s (len=%zu)\n", (int)value_length, value, value_length);
    value_count++;
}

static kjson_event_handlers_t handlers = {
    .on_object_start = on_object_start,
    .on_object_end = on_object_end,
    .on_array_start = on_array_start,
    .on_array_end = on_array_end,
    .on_key = on_key,
    .on_value = on_value,
    .on_error = NULL
};

static void test_simple_object(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{\"key\": \"value\"}";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    printf("object_end_count: %d\n", object_end_count);
    printf("object_start_count: %d\n", object_start_count);
    printf("key_count: %d\n", key_count);
    printf("value_count: %d\n", value_count);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(object_start_count, 1);
    assert_int_equal(object_end_count, 1);
    assert_int_equal(key_count, 1);
    assert_int_equal(value_count, 1);
    
    kjson_parser_destroy(parser);
}

static void test_nested_object(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{\"a\": {\"b\": 1}}";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    if (status != KJSON_OK) {
        printf("Parse failed with status: %d\n", status);
    }
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(object_start_count, 2);
    assert_int_equal(object_end_count, 2);
    assert_int_equal(key_count, 2);
    assert_int_equal(value_count, 1); // "1" is the only value, objects are containers
    
    kjson_parser_destroy(parser);
}

static void test_array(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[1, 2, 3]";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    if (status != KJSON_OK) {
        printf("Parse failed with status: %d\n", status);
    }
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(array_start_count, 1);
    assert_int_equal(array_end_count, 1);
    assert_int_equal(value_count, 3);
    
    kjson_parser_destroy(parser);
}

static void test_mixed(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "{\"arr\": [true, false, null]}";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(object_start_count, 1);
    assert_int_equal(array_start_count, 1);
    assert_int_equal(key_count, 1);
    assert_int_equal(value_count, 3);
    
    kjson_parser_destroy(parser);
}

static void test_loose_types(void **state) {
    reset_counts();
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[0xFF, NaN, Inf, .123]";
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &handlers, NULL);
    
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(value_count, 4);
    
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
