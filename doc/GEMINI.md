# Project Context: kJSON

## Project Overview
kJSON is intended to be a lightweight, read-only SAX-style parser for JSON and JSON5, written in C. It aims to be robust, fast, and suitable for streaming applications like IDS/IPS devices.

**Key Features (Planned):**
*   **Standards:** JSON and JSON5 compatible.
*   **Architecture:** Event-driven (SAX-style) using callbacks.
*   **Technology:** C language, leveraging [Ragel](https://www.colm.net/open-source/ragel/) for state machine generation.
*   **Design:** Zero-copy, thread-safe, no external runtime dependencies.

## Current Status
**State:** Active Development.
*   `src/kjson.rl`: Implemented JSON/JSON5 grammar with loose type handling (primitives as strings).
*   `src/kjson.c`: Generated from Ragel source.
*   `include/kjson.h`: Defined parser structs and callbacks.
*   `test/`: Contains `test_basic.c`, `test_standard.c`, and `test_json5.c`.
*   Build System: CMake set up and working.

## Intended Architecture & API
Based on the `README.md`, the library is designed around a parser object and a set of callback handlers.

### Core Structure
*   **Parser Handle:** `kjson_parser_t`
*   **Configuration:** `kjson_config_t`
*   **Handlers:** `kjson_event_handlers_t` containing function pointers for:
    *   `on_object_start` / `on_object_end`
    *   `on_array_start` / `on_array_end`
    *   `on_key`
    *   `on_value`
    *   `on_error`

### Planned Workflow
1.  Initialize parser: `kjson_parser_create(config)`
2.  Register callbacks in `parser->handler`.
3.  Feed data: `kjson_parse(parser, data, length, handlers, user_data)`
4.  Cleanup: `kjson_parser_destroy(parser)`

## Development Roadmap
1.  **Build System Setup:** [Completed]
2.  **Header Definition:** [Completed]
3.  **State Machine Implementation:** [Completed]
    *   Basic JSON grammar.
    *   Loose type handling (primitives as strings).
    *   JSON5 support (comments, trailing commas, unquoted keys, single quotes).
4.  **Driver Code:** [Completed]
5.  **Testing:** [In Progress]
    *   Basic tests passing.
    *   Standard JSON tests passing.
    *   JSON5 tests passing.

## Commands
*   **Build:** `mkdir build && cd build && cmake .. && make`
*   **Test:** `ctest` or `./test/runner`
