#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kjson.h"

typedef struct {
    int depth;
} cli_context_t;

static void print_indent(int depth) {
    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }
}

static void on_object_start(size_t offset, void* user_data) {
    cli_context_t* ctx = (cli_context_t*)user_data;
    print_indent(ctx->depth);
    printf("Object {\n");
    ctx->depth++;
}

static void on_object_end(size_t offset, void* user_data) {
    cli_context_t* ctx = (cli_context_t*)user_data;
    ctx->depth--;
    print_indent(ctx->depth);
    printf("}\n");
}

static void on_array_start(size_t offset, void* user_data) {
    cli_context_t* ctx = (cli_context_t*)user_data;
    print_indent(ctx->depth);
    printf("Array [\n");
    ctx->depth++;
}

static void on_array_end(size_t offset, void* user_data) {
    cli_context_t* ctx = (cli_context_t*)user_data;
    ctx->depth--;
    print_indent(ctx->depth);
    printf("]\n");
}

static void on_key(const char* key, size_t key_length, void* user_data) {
    cli_context_t* ctx = (cli_context_t*)user_data;
    print_indent(ctx->depth);
    printf("Key: %.*s\n", (int)key_length, key);
}

static void on_value(const char* value, size_t value_length, void* user_data) {
    cli_context_t* ctx = (cli_context_t*)user_data;
    print_indent(ctx->depth);
    printf("Value: %.*s\n", (int)value_length, value);
}

static void on_error(const char* error_message, size_t error_length, void* user_data) {
    fprintf(stderr, "Error: %.*s\n", (int)error_length, error_message);
}

static kjson_event_handlers_t handlers = {
    .on_object_start = on_object_start,
    .on_object_end = on_object_end,
    .on_array_start = on_array_start,
    .on_array_end = on_array_end,
    .on_key = on_key,
    .on_value = on_value,
    .on_error = on_error
};

int main(int argc, char** argv) {
    FILE* input = stdin;
    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            perror("Failed to open file");
            return 1;
        }
    }

    char* buffer = NULL;
    size_t read_size = 0;

    if (input == stdin) {
        size_t capacity = 1024;
        buffer = (char*)malloc(capacity);
        if (!buffer) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        
        while (1) {
            size_t bytes = fread(buffer + read_size, 1, capacity - read_size, input);
            if (bytes == 0) break;
            read_size += bytes;
            if (read_size == capacity) {
                capacity *= 2;
                char* new_buffer = (char*)realloc(buffer, capacity);
                if (!new_buffer) {
                    free(buffer);
                    fprintf(stderr, "Memory allocation failed\n");
                    return 1;
                }
                buffer = new_buffer;
            }
        }
        buffer[read_size] = '\0';
    } else {
        fseek(input, 0, SEEK_END);
        long length = ftell(input);
        fseek(input, 0, SEEK_SET);

        buffer = (char*)malloc(length + 1);
        if (!buffer) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(input);
            return 1;
        }

        read_size = fread(buffer, 1, length, input);
        buffer[read_size] = '\0';
        fclose(input);
    }

    kjson_parser_t* parser = kjson_parser_create(NULL);
    cli_context_t ctx = {0};

    kjson_status_t status = kjson_parse(parser, buffer, read_size, &handlers, &ctx);

    free(buffer);
    kjson_parser_destroy(parser);

    if (status != KJSON_OK) {
        fprintf(stderr, "Parse failed with status: %d\n", status);
        return 1;
    }

    return 0;
}
