#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/headers/parser.h"

static int LENGTH_OF_SRC;
static char *SOURCE = "";
static Parser *parser;

TokenName token_names[] = {
    [NUMBER] = {"NUMBER"}, [EQUALS_EQUALS] = {"=="},  [EQUALS] = {"="},
    [SEMI_COLON] = {";"},  [END_OF_FILE] = {"\nEOF"},
};

// Parsing utilities.
char peek() { return *(SOURCE + 1); }

void advance() { SOURCE++; }

void print_tokens(TokenType *tokens) {
    for (int i = 0; tokens[i] != END_OF_FILE; i++) {
        TokenType cur_token = tokens[i];
        char *name = token_names[cur_token].name;
        printf("%s ", name);
    }

    printf("\n");
}

void parse_number() {
    while (isalnum(*SOURCE)) {
        char next = peek();
        if (isalnum(next)) {
            advance();
            continue;
        }

        *(parser->tokens + parser->index) = NUMBER;
        parser->index++;
        advance();
        break;
    }

    skip_space();
}

void skip_space() {
    while (*SOURCE == ' ' || peek() == ' ') {
        advance();
    }
}

void parse(char *source) {
    SOURCE = source;
    LENGTH_OF_SRC = sizeof(source);

    parser = malloc(sizeof(Parser));
    parser->tokens = malloc(sizeof(TokenType) * LENGTH_OF_SRC);
    parser->index = 0;

    // While loop done here
    while (*SOURCE != '\0' || *SOURCE != '\000') {
        TokenType cur_token;
        char next;

        skip_space();

        next = peek();
        if (isalnum(next)) {
            parse_number();
        }

        if (*SOURCE == '=') {
            char next = peek();
            if (next == '=') {
                cur_token = EQUALS_EQUALS;
                // Since '==' is one token, advance to the next '='
                advance();
            } else {
                // If it's just '='
                cur_token = EQUALS;
            }
        }

        if (*SOURCE == ';') {
            cur_token = SEMI_COLON;
        }

        // Advance to next
        *(parser->tokens + parser->index) = cur_token;
        // Only increment the index if something has been added
        // to the list of tokens.
        parser->index++;
        advance();
    }

    *(parser->tokens + parser->index) = END_OF_FILE;
    print_tokens(parser->tokens);
}
