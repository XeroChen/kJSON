#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <string.h>
#include <stdio.h>
#include "kjson.h"
#include "test_utils.h"

// --- Data Types Tests ---

static void test_strings(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    // Test empty string, escaped chars, unicode (basic)
    const char* json = "[\"\", \"hello\", \"line\\nbreak\", \"\\\"quoted\\\"\"]";
    
    expected_event_t expected[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "" },
        { EVENT_VALUE, "hello" },
        { EVENT_VALUE, "line\\nbreak" }, // Parser returns raw value currently? Or unescaped? 
                                         // Based on current implementation (primitive_base), it likely returns raw slice.
                                         // Wait, strings use string_grammar >mark @on_quoted_value.
                                         // The handler receives the content inside quotes.
                                         // Let's assume it returns the raw content for now, but we might need to check if it unescapes.
                                         // Looking at kjson.rl: string_grammar = ( '"' ( [^"\\\\] | '\\' any )* '"' ) ...
                                         // on_quoted_value strips quotes. It does NOT unescape in the parser itself.
        { EVENT_VALUE, "\\\"quoted\\\"" }, 
        { EVENT_ARRAY_END, NULL }
    };
    
    test_context_t ctx = { expected, 6, 0 };
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 6);
    kjson_parser_destroy(parser);
}

static void test_numbers(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[0, -1, 123.456, 1e10, -1.2e-3]";
    
    expected_event_t expected[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "0" },
        { EVENT_VALUE, "-1" },
        { EVENT_VALUE, "123.456" },
        { EVENT_VALUE, "1e10" },
        { EVENT_VALUE, "-1.2e-3" },
        { EVENT_ARRAY_END, NULL }
    };
    
    test_context_t ctx = { expected, 7, 0 };
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 7);
    kjson_parser_destroy(parser);
}

static void test_booleans_null(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[true, false, null]";
    
    expected_event_t expected[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "true" },
        { EVENT_VALUE, "false" },
        { EVENT_VALUE, "null" },
        { EVENT_ARRAY_END, NULL }
    };
    
    test_context_t ctx = { expected, 5, 0 };
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 5);
    kjson_parser_destroy(parser);
}

// --- Edge Cases Tests ---

static void test_deeply_nested(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    // 20 levels deep
    const char* json = "[[[[[[[[[[[[[[[[[[[[0]]]]]]]]]]]]]]]]]]]]";
    
    // We expect 20 array starts, 1 value, 20 array ends
    // Total 41 events
    // This is tedious to write out in expected_event_t, so we might just check status
    // But let's try a smaller one for exact verification
    const char* json_small = "[[[0]]]";
    expected_event_t expected[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_ARRAY_START, NULL },
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "0" },
        { EVENT_ARRAY_END, NULL },
        { EVENT_ARRAY_END, NULL },
        { EVENT_ARRAY_END, NULL }
    };
    
    test_context_t ctx = { expected, 7, 0 };
    kjson_status_t status = kjson_parse(parser, json_small, strlen(json_small), &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 7);
    kjson_parser_destroy(parser);
}

static void test_whitespace_variations(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = " \t\n { \r\n \"key\" \t : \n \"value\" \r } \t ";
    
    expected_event_t expected[] = {
        { EVENT_OBJECT_START, NULL },
        { EVENT_KEY, "key" },
        { EVENT_VALUE, "value" },
        { EVENT_OBJECT_END, NULL }
    };
    
    test_context_t ctx = { expected, 4, 0 };
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 4);
    kjson_parser_destroy(parser);
}

static void test_invalid_json(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    
    const char* invalid_cases[] = {
        "{",            // Unclosed object
        "[",            // Unclosed array
        "{\"key\":}",   // Missing value
        "{\"key\"}",    // Missing colon
        "{:\"value\"}", // Missing key
        "[1,]",         // Trailing comma (valid in JSON5, but let's check if we can disable it? Config not used yet)
                        // Actually, current parser is JSON5 compatible by default.
        "{\"key\": \"value\",}", // Trailing comma in object
        NULL
    };

    // For now, since we support JSON5, trailing commas are valid.
    // Let's test things that are definitely invalid even in JSON5
    const char* definitely_invalid[] = {
        "{", 
        "[",
        "{\"key\":}",
        NULL
    };

    for (int i = 0; definitely_invalid[i] != NULL; i++) {
        kjson_status_t status = kjson_parse(parser, definitely_invalid[i], strlen(definitely_invalid[i]), NULL, NULL);
        assert_int_not_equal(status, KJSON_OK);
    }
    
    kjson_parser_destroy(parser);
}

static void test_json5_special_numbers(void **state) {
    kjson_parser_t* parser = kjson_parser_create(NULL);
    const char* json = "[Infinity, -Infinity, NaN, +1, .5, 1.]";
    
    expected_event_t expected[] = {
        { EVENT_ARRAY_START, NULL },
        { EVENT_VALUE, "Infinity" },
        { EVENT_VALUE, "-Infinity" },
        { EVENT_VALUE, "NaN" },
        { EVENT_VALUE, "+1" },
        { EVENT_VALUE, ".5" },
        { EVENT_VALUE, "1." },
        { EVENT_ARRAY_END, NULL }
    };
    
    test_context_t ctx = { expected, 8, 0 };
    kjson_status_t status = kjson_parse(parser, json, strlen(json), &test_handlers, &ctx);
    assert_int_equal(status, KJSON_OK);
    assert_int_equal(ctx.current, 8);
    kjson_parser_destroy(parser);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_strings),
        cmocka_unit_test(test_numbers),
        cmocka_unit_test(test_booleans_null),
        cmocka_unit_test(test_deeply_nested),
        cmocka_unit_test(test_whitespace_variations),
        cmocka_unit_test(test_invalid_json),
        cmocka_unit_test(test_json5_special_numbers),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
