#ifndef PARSER_H
#define PARSER_H

#include "types.h"

typedef struct Parser {
    TokenType *tokens;
    int index;
} Parser;

char peek();

char advance();

void parse(char *source);

void parse_string(char *source);

// To compare two objects. Make it simple have it compare numbers instead.
int equality(int x, int y);

int binary(int x, int y);

#endif
