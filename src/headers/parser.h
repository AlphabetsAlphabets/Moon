#ifndef PARSER_H
#define PARSER_H

#include "types.h"

typedef struct Parser {
    TokenType *tokens;
    int index;
} Parser;

void parse(char *source);

void skip_space();

void parse_number();

void print_tokens(TokenType *tokens);

char peek();

void advance();

#endif
