#ifndef KJSON_H
#define KJSON_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct kjson_parser_s kjson_parser_t;

typedef struct {
    size_t max_depth;
    size_t max_string_length;
    int allow_json5;
} kjson_config_t;

typedef enum {
    KJSON_OK = 0,
    KJSON_ERROR_INVALID_JSON,
    KJSON_ERROR_MEMORY,
    KJSON_ERROR_MAX_DEPTH_EXCEEDED,
    KJSON_ERROR_MAX_STRING_LENGTH_EXCEEDED,
    KJSON_ERROR_USER_ABORT
} kjson_status_t;

typedef struct {
    void (*on_object_start)(size_t offset, void* user_data);
    void (*on_object_end)(size_t offset, void* user_data);
    void (*on_array_start)(size_t offset, void* user_data);
    void (*on_array_end)(size_t offset, void* user_data);
    void (*on_key)(const char* key, size_t key_length, void* user_data);
    void (*on_value)(const char* value, size_t value_length, void* user_data);
    void (*on_error)(const char* error_message, size_t error_length, void* user_data);
} kjson_event_handlers_t;

kjson_parser_t* kjson_parser_create(kjson_config_t* config);
kjson_status_t kjson_parse(kjson_parser_t* parser, const char* data, size_t length, kjson_event_handlers_t* handlers, void* user_data);
void kjson_parser_destroy(kjson_parser_t* parser);

#ifdef __cplusplus
}
#endif

#endif // KJSON_H
