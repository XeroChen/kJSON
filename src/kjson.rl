#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "kjson.h"

struct kjson_parser_s {
    kjson_config_t config;
    int cs;
    int top;
    int stack[32]; // Fixed stack for now, should be dynamic or based on config
    const char* mark;
};

%%{
    machine kjson;
    
    # Access the state in the parser struct
    access parser->;
    variable cs parser->cs;
    variable top parser->top;
    variable stack parser->stack;

    action mark {
        parser->mark = p;
    }

    action on_object_start {
        if (handlers && handlers->on_object_start) 
            handlers->on_object_start(p - data, user_data);
    }

    action on_object_end {
        if (handlers && handlers->on_object_end) 
            handlers->on_object_end(p - data, user_data);
    }

    action on_array_start {
        if (handlers && handlers->on_array_start) 
            handlers->on_array_start(p - data, user_data);
    }

    action on_array_end {
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }

    action on_key {
        if (handlers && handlers->on_key)
            handlers->on_key(parser->mark, p - parser->mark, user_data);
    }

    action on_quoted_key {
        if (handlers && handlers->on_key) {
            // Strip quotes
            handlers->on_key(parser->mark + 1, p - parser->mark - 1, user_data);
        }
    }

    action on_value {
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }

    action on_quoted_value {
        if (handlers && handlers->on_value) {
            // Strip quotes
            handlers->on_value(parser->mark + 1, p - parser->mark - 1, user_data);
        }
    }

    action debug {
        // printf("Debug: char='%c' cs=%d top=%d\n", *p, parser->cs, parser->top);
    }

    # JSON Grammar
    # Comments
    single_line_comment = '//' [^\n]* '\n';
    multi_line_comment = '/*' ( any* - (any* '*/' any*) ) '*/';
    comment = single_line_comment | multi_line_comment;
    
    ws = ([ \t\n\r] | comment)+;

    
    # Forward declarations
    action call_value { fcall value; }
    action call_value_on_char { fhold; fcall value; }
    action do_return { fret; }
    action start_primitive { parser->mark = p; }

    # String: " chars " or ' chars '
    string_grammar = ( '"' ( [^"\\\\] | '\\' any )* '"' ) |
                     ( "'" ( [^'\\\\] | '\\' any )* "'" );

    # Identifier (Unquoted key)
    identifier = [a-zA-Z$_] [a-zA-Z0-9$_]*;
    
    quoted_key = string_grammar >mark @on_quoted_key;
    unquoted_key = identifier >mark %on_key;
    key_parser = quoted_key | unquoted_key;

    # Simplified primitive value (numbers, bools, null, NaN, Inf, etc.)
    # Matches anything that is not a delimiter or whitespace
    delimiter = [ \t\n\r\{\}\[\],":/];
    primitive_base = ( any - delimiter )+ >start_primitive delimiter @on_value @{ fhold; };
    primitive_eof = ( any - delimiter )+ >start_primitive %/on_value;

    # Machines
    
    object := (
        ws* '}' @on_object_end @{ fret; } |
        ws* key_parser ws* ':' @call_value (
            ws* ',' ws* (
                ( key_parser ws* ':' @call_value ) |
                ( '}' @on_object_end @{ fret; } )
            )
        )* ws* '}' @on_object_end @{ fret; }
    );

    start_value_char = any - [ \t\n\r\]];

    array := (
        ws* ']' @on_array_end @{ fret; } |
        ws* ( start_value_char >call_value_on_char ) (
            ws* ',' ws* (
                ( start_value_char >call_value_on_char ) |
                ( ']' @on_array_end @{ fret; } )
            )
        )* ws* ']' @on_array_end @{ fret; }
    );

    return_state := empty @do_return;

    value_recursive_expr = (
        ws* (
            string_grammar >mark @on_quoted_value @do_return |
            primitive_base @do_return |
            '{' @on_object_start @{ fgoto object; } |
            '[' @on_array_start @{ fgoto array; }
        )
    );

    value := value_recursive_expr;

    main := (
        ws* (
            string_grammar >mark @on_quoted_value |
            primitive_base |
            primitive_eof |
            '{' @on_object_start @{ fcall object; } |
            '[' @on_array_start @{ fcall array; }
        ) ws*
    );

    write data;
}%%

kjson_parser_t* kjson_parser_create(kjson_config_t* config) {
    kjson_parser_t* parser = (kjson_parser_t*)malloc(sizeof(kjson_parser_t));
    if (!parser) return NULL;

    if (config) {
        parser->config = *config;
    } else {
        parser->config.max_depth = 32;
        parser->config.max_string_length = 1024;
        parser->config.allow_json5 = 1;
    }
    
    %% write init;
    
    return parser;
}

void kjson_parser_destroy(kjson_parser_t* parser) {
    if (parser) {
        free(parser);
    }
}

kjson_status_t kjson_parse(kjson_parser_t* parser, const char* data, size_t length, kjson_event_handlers_t* handlers, void* user_data) {
    if (!parser || !data) return KJSON_ERROR_INVALID_JSON;

    const char* p = data;
    const char* pe = data + length;
    const char* eof = pe;

    printf("Parsing: %.*s\n", (int)length, data);

    %% write exec;

    if (parser->cs == kjson_error) {
        return KJSON_ERROR_INVALID_JSON;
    }
    if (parser->cs < kjson_first_final) {
        return KJSON_ERROR_INVALID_JSON;
    }

    return KJSON_OK;
}
