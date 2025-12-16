#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "kjson.h"

// No-op handlers for fuzzing speed
static void on_object_start(size_t offset, void* user_data) {}
static void on_object_end(size_t offset, void* user_data) {}
static void on_array_start(size_t offset, void* user_data) {}
static void on_array_end(size_t offset, void* user_data) {}
static void on_key(const char* key, size_t key_length, void* user_data) {}
static void on_value(const char* value, size_t value_length, void* user_data) {}
static void on_error(const char* error_message, size_t error_length, void* user_data) {}

static kjson_event_handlers_t handlers = {
    .on_object_start = on_object_start,
    .on_object_end = on_object_end,
    .on_array_start = on_array_start,
    .on_array_end = on_array_end,
    .on_key = on_key,
    .on_value = on_value,
    .on_error = on_error
};

// __AFL_FUZZ_INIT();

int main(int argc, char** argv) {
    
#ifdef __AFL_HAVE_MANUAL_CONTROL
    __AFL_INIT();
#endif

    char* buffer = NULL;
    size_t length = 0;
    
    // Read from stdin (AFL default)
    // For better performance with persistent mode, we would loop here.
    // But for simple start, reading stdin is fine.
    
    // Using a fixed large buffer for simplicity in fuzzing context
    #define BUF_SIZE 1024 * 1024
    buffer = (char*)malloc(BUF_SIZE);
    if (!buffer) return 1;

    ssize_t read_bytes = read(STDIN_FILENO, buffer, BUF_SIZE);
    if (read_bytes < 0) {
        free(buffer);
        return 1;
    }
    length = (size_t)read_bytes;

    kjson_parser_t* parser = kjson_parser_create(NULL);
    if (!parser) {
        free(buffer);
        return 1;
    }

    // We don't care about the status, just that it doesn't crash
    kjson_parse(parser, buffer, length, &handlers, NULL);

    kjson_parser_destroy(parser);
    free(buffer);

    return 0;
}
