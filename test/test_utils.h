#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stddef.h>
#include "kjson.h"

typedef enum {
    EVENT_OBJECT_START,
    EVENT_OBJECT_END,
    EVENT_ARRAY_START,
    EVENT_ARRAY_END,
    EVENT_KEY,
    EVENT_VALUE
} event_type_t;

typedef struct {
    event_type_t type;
    const char* data; // For KEY and VALUE
} expected_event_t;

typedef struct {
    expected_event_t* expected;
    int count;
    int current;
} test_context_t;

void test_on_object_start(size_t offset, void* user_data);
void test_on_object_end(size_t offset, void* user_data);
void test_on_array_start(size_t offset, void* user_data);
void test_on_array_end(size_t offset, void* user_data);
void test_on_key(const char* key, size_t key_length, void* user_data);
void test_on_value(const char* value, size_t value_length, void* user_data);

extern kjson_event_handlers_t test_handlers;

#endif // TEST_UTILS_H
