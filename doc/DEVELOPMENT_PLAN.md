# kJSON Development Plan

This document outlines the high-level steps for developing the kJSON library, serving as a tracking mechanism for progress.

## Completed Tasks:

- [x] Build System Setup: Create `CMakeLists.txt` to handle Ragel generation and C compilation.
- [x] Header Definition: Populate `include/kjson.h` with the structs and function prototypes.
- [x] State Machine Implementation: Create a Ragel file (e.g., `src/kjson.rl`) to define the JSON/JSON5 grammar and generate parsing logic.
- [x] Driver Code: Implement the C glue code in `src/kjson.c`.
- [x] Testing: Set up the `test/` directory, likely using `cmocka`.

## Next Steps:

- [x] Grammar Implementation: Implement standard JSON grammar (strings, numbers, bools, null) - *Simplified to treat primitives as strings*.
- [x] JSON5 Support: Add JSON5 specific features (comments, trailing commas, unquoted keys, etc.).
- [x] Build System Enhancements: Add install targets and pkg-config support.
- [x] CLI Tool: Create a `kjson` command-line tool for parsing JSON from stdin or file.
- [ ] Comprehensive Testing: Add tests for all data types and edge cases.

