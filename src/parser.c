#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "src/headers/parser.h"
#include "src/headers/types.h"

// 1 == 2 == 3
// Sees 1, then =, then =. In its memory it sees 1 ==,
// scans and sees 2. Evaluates 1 == 2. What's left is
// 0 == 3. Goes through the same loop and returns 0.

static int LENGTH_OF_SRC;
static char* SOURCE = "";

char peek() {
    char next = *(SOURCE + 1);
    SOURCE--;
    return next;
}

char advance() {
    return *(++SOURCE);
}

void parse(char *source) {
    SOURCE = source;
    LENGTH_OF_SRC = sizeof(source);

    Parser parser = {};

    for (int i = 0; i < LENGTH_OF_SRC; i++) {
        char current_char = *(SOURCE + i);
        char next_char = peek();

        TokenType *current_token = parser.tokens + i;

        if (current_char == '"') {
            int current_index = i;
            while (next_char != '"' && i < LENGTH_OF_SRC) {
                SOURCE++;
                i++;
            }

            if (i == LENGTH_OF_SRC) {
                // String not terminated
                printf("\n\nString not terminated\n");
            } else {
                // FIXME
                // Source would be from current_index until i;
                // Slicing: https://stackoverflow.com/questions/27725222/array-slicing-in-c
                DataType type = { STRING, SOURCE };
            }
        }

        if (isalnum(current_char)) {
            *current_token = NUMBER;
        }

        parser.index = i;
    }
}

void parse_string(char *source) {}
