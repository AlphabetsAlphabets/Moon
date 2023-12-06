#ifndef PARSER_H
#define PARSER_H

#include "types.h"

typedef struct Parser {
    TokenType *tokens;
    int index;
} Parser;

void parse(char *source);

void print_tokens(TokenType *tokens);

#endif
