#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <string.h>
#include <stdio.h>
#include "test_utils.h"

void test_on_object_start(size_t offset, void* user_data) {
    test_context_t* ctx = (test_context_t*)user_data;
    assert_true(ctx->current < ctx->count);
    assert_int_equal(ctx->expected[ctx->current].type, EVENT_OBJECT_START);
    ctx->current++;
}

void test_on_object_end(size_t offset, void* user_data) {
    test_context_t* ctx = (test_context_t*)user_data;
    assert_true(ctx->current < ctx->count);
    assert_int_equal(ctx->expected[ctx->current].type, EVENT_OBJECT_END);
    ctx->current++;
}

void test_on_array_start(size_t offset, void* user_data) {
    test_context_t* ctx = (test_context_t*)user_data;
    assert_true(ctx->current < ctx->count);
    assert_int_equal(ctx->expected[ctx->current].type, EVENT_ARRAY_START);
    ctx->current++;
}

void test_on_array_end(size_t offset, void* user_data) {
    test_context_t* ctx = (test_context_t*)user_data;
    assert_true(ctx->current < ctx->count);
    assert_int_equal(ctx->expected[ctx->current].type, EVENT_ARRAY_END);
    ctx->current++;
}

void test_on_key(const char* key, size_t key_length, void* user_data) {
    test_context_t* ctx = (test_context_t*)user_data;
    assert_true(ctx->current < ctx->count);
    assert_int_equal(ctx->expected[ctx->current].type, EVENT_KEY);
    
    const char* expected_key = ctx->expected[ctx->current].data;
    assert_int_equal(key_length, strlen(expected_key));
    assert_memory_equal(key, expected_key, key_length);
    
    ctx->current++;
}

void test_on_value(const char* value, size_t value_length, void* user_data) {
    test_context_t* ctx = (test_context_t*)user_data;
    assert_true(ctx->current < ctx->count);
    assert_int_equal(ctx->expected[ctx->current].type, EVENT_VALUE);
    
    const char* expected_value = ctx->expected[ctx->current].data;
    assert_int_equal(value_length, strlen(expected_value));
    assert_memory_equal(value, expected_value, value_length);
    
    ctx->current++;
}

kjson_event_handlers_t test_handlers = {
    .on_object_start = test_on_object_start,
    .on_object_end = test_on_object_end,
    .on_array_start = test_on_array_start,
    .on_array_end = test_on_array_end,
    .on_key = test_on_key,
    .on_value = test_on_value,
    .on_error = NULL
};
