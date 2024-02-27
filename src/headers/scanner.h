#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokens.h"

static int NUM_TOKENS = 0;

// Moon's scanner. Turns source code into lexemes
// then turn those lexemes into tokens
typedef struct Scanner {
    char *source;
    Token *tokens;
    int line;
    int column;
    int has_error;
} Scanner;

// Scans through source code.
void scan(Scanner *scanner);
void identify_token(Scanner *scanner, char *ch);

char advance(Scanner *scanner);
char peak(Scanner *scanner);

void print_token(Scanner *scanner);

#endif
