#ifndef TOKENS_H
#define TOKENS_H

typedef enum TokenType {
    NUMBER,
    STRING,
    SEMI_COLON,
    END_OF_FILE,

    // Equality
    BANG,
    EQUALS,
    EQUALS_EQUALS,
    BANG_EQUALS,
    GREATER_EQUALS,
    LESS_EQUALS,
} TokenType;

typedef struct TokenName {
    char *name;
} TokenName;

extern TokenName token_names[];

#endif
