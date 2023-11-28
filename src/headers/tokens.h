#ifndef TOKENS_H
#define TOKENS_H

typedef enum TokenType {
    NUMBER,
    STRING,

    // Equality
    BANG,
    EQUALS_EQUALS,
    BANG_EQUALS,
    GREATER_EQUALS,
    LESS_EQUALS,
} TokenType;

#endif

