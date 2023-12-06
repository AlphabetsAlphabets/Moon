#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "src/headers/parser.h"

static int LENGTH_OF_SRC;
static char *SOURCE = "";

TokenName token_names[] = {
    [NUMBER] = {"NUMBER"}, [EQUALS_EQUALS] = {"=="},  [EQUALS] = {"="},
    [SEMI_COLON] = {";"},  [END_OF_FILE] = {"\nEOF"},
};

// dest should be +1 longer to accomodate for the insertion of the NULL
// character.
void slice(const char *src, char *dest, size_t start, size_t end) {
    strncpy(dest, src + start, end - start);
}

void print_tokens(TokenType *tokens) {
    printf("'");
    for (int i = 0; tokens[i] != END_OF_FILE; i++) {
        TokenType cur_token = tokens[i];
        char *name = token_names[cur_token].name;
        printf("%s ", name);
    }

    printf("'");
    printf("\n");
}

void parse(char *source) {
    SOURCE = source;
    LENGTH_OF_SRC = sizeof(source);

    Parser *parser = malloc(sizeof(Parser));
    parser->tokens = malloc(sizeof(TokenType) * LENGTH_OF_SRC);
    parser->index = 0;

    // While loop done here
    while (*SOURCE != '\0' || *SOURCE != '\000') {
        TokenType cur_token = END_OF_FILE;
        if (isalnum(*SOURCE)) {
            cur_token = NUMBER;
        }

        if (*SOURCE == '=') {
            char next = *(SOURCE + 1);
            if (next == '=') {
                cur_token = EQUALS_EQUALS;
                // Since '==' is one token, advance to the next '='
                SOURCE++;
                parser->index++;
            } else {
                // If it's just '='
                cur_token = EQUALS;
            }
        }

        if (*SOURCE == ';') {
            cur_token = SEMI_COLON;
        }

        // Advance to next
        // FIXME
        // The tokens don't actually get saved.
        *(parser->tokens + parser->index) = cur_token;
        parser->index++;
        SOURCE++;
    }

    *(parser->tokens + 1) = END_OF_FILE;
    print_tokens(parser->tokens);
}
