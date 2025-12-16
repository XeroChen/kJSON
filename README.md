# kJSON

## Why kJSON: A Technical Challenge of Robust JSON+JSON5 SAX-Style Parsing
This is a difficult requirement to fulfill perfectly. There are very few direct equivalents to yajl (a low-level C, event-driven/SAX-style parser) that also support the full JSON5 specification.

Here is why this combination is rare, followed by the best available open-source options.

The Technical Challenge
The reason you don't find many streaming JSON5 parsers is that JSON5 features make streaming extremely difficult compared to strict JSON.

Strict JSON (like yajl): It is very easy to parse byte-by-byte using a simple state machine. When you see a `{`, you enter "object state." When you see a `"`, you enter "string state."

JSON5: Features like multi-line comments `/* ... */` and trailing commas throw a wrench into streaming.

If your input stream chunk ends right in the middle of a comment marker (e.g., the chunk ends with `/`), the parser cannot know if it's a division symbol or the start of a comment until it gets the next chunk.

Handling unquoted keys requires significantly more lookahead buffering than strict JSON strings.

Because of this complexity, most JSON5 parsers choose to load the entire document into memory (DOM style) before parsing.

## Overview

kJSON is a lightweight JSON (JavaScript Object Notation) **READ-ONLY** SAX-style parser written in C leveraging [**Ragel**](https://www.colm.net/open-source/ragel/). It is compatible with JSON and JSON5. It is designed for robust, fast and easy parsing of the JSON data stream in WAF like IDS/IPS devices.

## Features

- **Compatibility**: Fully compatible with JSON and JSON5 standards.
- **Lightweight**: Minimal memory footprint, making it suitable for resource-constrained environments.
- **Fast Parsing**: Optimized for speed, allowing quick parsing of large JSON data streams.
- **Easy Integration**: Simple API for easy integration into existing projects.
- **Streaming Support**: Capable of parsing JSON data streams, with SAX-like event-driven parsing.
- **Error Handling**: Provides detailed error messages for easier debugging.
- **Extensibility**: Designed to be easily extendable for custom data types and structures.
- **Cross-Platform**: Works across various platforms and environments.
- **String Only Mode**: Parse all elements(key, value, list) as string values.
- **No External Dependencies**: Does not rely on external libraries, ensuring ease of deployment.
- **Thread-Safe**: Safe for use in multi-threaded applications.
- **Zero-Copy Parsing**: Minimizes data copying for improved performance.
- **Configurable Limits**: Allows setting limits on nesting depth and string length to prevent resource exhaustion.
- **Tolerant**: Handles minor syntax errors gracefully, allowing for more robust parsing in real-world scenarios.

## CLI Tool

kJSON includes a command-line tool `kjson` for parsing JSON from standard input or files.

```bash
# Parse from stdin
echo '{"key": "value"}' | kjson

# Parse from file
kjson data.json
```

## Core API

The core API of kJSON provides functions for parsing JSON data streams and handling parsing events. The main components include:

- **Parser Initialization**: Functions to create and configure a parser instance.

```C
#include "kjson.h"
kjson_parser_t* kjson_parser_create(kjson_config_t* config);

```

- **Event Handlers**: Callback functions for handling parsing events such as the start and end of objects and arrays, key-value pairs, and errors.

```C
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
kjson_parser_t->handler->on_object_start = my_object_start_handler;
kjson_parser_t->handler->on_object_end = my_object_end_handler;
kjson_parser_t->handler->on_array_start = my_array_start_handler;
kjson_parser_t->handler->on_array_end = my_array_end_handler;
kjson_parser_t->handler->on_key = my_key_handler;
kjson_parser_t->handler->on_value = my_value_handler;
kjson_parser_t->handler->on_error = my_error_handler;
```

- **Parsing Function**: A function to feed JSON data into the parser and trigger the parsing
process.

```C
kjson_status_t kjson_parse(kjson_parser_t* parser, const char* data, size_t length, kjson_event_handlers_t* handlers, void* user_data);
```

- **Parser Destruction**: Functions to clean up and free parser resources.

```C
void kjson_parser_destroy(kjson_parser_t* parser);
```

## Fuzz Testing

kJSON supports fuzz testing with AFL++.

1.  **Build with AFL++**:
    ```bash
    mkdir build_fuzz && cd build_fuzz
    CC=afl-cc cmake -DENABLE_FUZZING=ON ..
    make
    ```

2.  **Run Fuzzer**:
    You can run the fuzzer directly using the CMake target:
    ```bash
    make fuzz
    ```
    
    Or manually:
    ```bash
    afl-fuzz -i ../test/corpus -o fuzz_out -- ./kjson_fuzz
    ```

## Build Dependencies

- **Ragel** (for state machine generation)
- **Standard C Library**
- **CMake** (for build configuration)
- **cmocka** (Unit Testing Framework)
- **gcov/lcov** (for code coverage analysis)
- **AFL++** (for fuzz testing)
- **Valgrind** (for memory leak detection) 

## Documentation

- [Context and Instructions](doc/GEMINI.md)
- [Development Plan](doc/DEVELOPMENT_PLAN.md)

