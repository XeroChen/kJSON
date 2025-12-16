#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "kjson.h"

static void test_create_destroy(void **state) {
    (void) state; /* unused */
    kjson_parser_t* parser = kjson_parser_create(NULL);
    assert_non_null(parser);
    kjson_parser_destroy(parser);
}

static void test_parse_empty_object(void **state) {
    (void) state; /* unused */
    kjson_parser_t* parser = kjson_parser_create(NULL);
    kjson_event_handlers_t handlers = {0};
    const char* json = "{}";
    kjson_status_t status = kjson_parse(parser, json, 2, &handlers, NULL);
    assert_int_equal(status, KJSON_OK);
    kjson_parser_destroy(parser);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_destroy),
        cmocka_unit_test(test_parse_empty_object),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
