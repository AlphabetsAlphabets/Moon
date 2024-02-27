#ifndef TOKENS_H
#define TOKENS_H

typedef enum TokenType {
    //////////////
    // Not done //
    //////////////
    NUMBER,
    STRING,

    //////////
    // Done //
    //////////
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    STAR,
    NEWLINE,
    MODULUS,
    END_OF_FILE,

    // Equality
    BANG,
    EQUALS,
    EQUALS_EQUALS,
    BANG_EQUALS,
    GREATER_EQUALS,
    LESS_EQUALS,
} TokenType;

// Contains information about the token
typedef struct Token {
    TokenType type;
    // The character that represents the TokenType
    char *lexeme;
    // The value to be evaluated.
    // To convert with *(type *)token.literal
    void *literal;
    int line;
} Token;

typedef struct TokenName {
    char *name;
} TokenName;

// Human readable string of tokens. Used for pretty printing.
extern TokenName token_names[];

#endif
