#include "src/headers/scanner.h"
#include "tokens.h"

TokenName token_names[] = {
    [STAR] = {"STAR"},
    [SEMICOLON] = {"SEMICOLON"},
    [PLUS] = {"PLUS"},
    [MINUS] = {"MINUS"},
    [DOT] = {"DOT"},
    [COMMA] = {"COMMA"},
    [RIGHT_BRACE] = {"RIGHT_BRACE"},
    [LEFT_BRACE] = {"LEFT_BRACE"},
    [RIGHT_PAREN] = {"RIGHT_PAREN"},
    [LEFT_PAREN] = {"LEFT_PAREN"},
    [NEWLINE] = {"NEWLINE"},
};

void print_token(Scanner *scanner) {
    Token token = *scanner->tokens;
    for (; token.type != END_OF_FILE;) {
        char *name = token_names[token.type].name;
        // FIXME: The lexeme doesn't match the token.
        char *lexeme = token.lexeme;
        printf("%s (%s) at line %i\n", name, lexeme, token.line);
        scanner->tokens++;
    }

    printf("\n");
}

void scan(Scanner *scanner) {
    // Initialise the scanner
    int length_of_src = strlen(scanner->source);
    scanner->tokens = malloc(sizeof(Token) * length_of_src);
    int *line = &scanner->line;
    int *column = &scanner->column;

    for (; NOT_FINISHED;) {
        char ch = *scanner->source;
        identify_token(scanner, ch);

        scanner->source++;
        (*column)++;
        NOT_FINISHED = *column < length_of_src;
    }

    Token eof_token = {END_OF_FILE, "EOF", "EOF", *line};
    *(scanner->tokens++) = eof_token;
}

void identify_token(Scanner *scanner, char ch) {
    TokenType token_type;
    // NOTE:
    // When adding new cases make sure to update
    // TokenName token_names[]
    switch (ch) {
    case '(':
        token_type = LEFT_PAREN;
        break;
    case ')':
        token_type = RIGHT_PAREN;
        break;
    case '{':
        token_type = LEFT_BRACE;
        break;
    case '}':
        token_type = RIGHT_BRACE;
        break;
    case ',':
        token_type = COMMA;
        break;
    case '.':
        token_type = DOT;
        break;
    case '-':
        token_type = MINUS;
        break;
    case '+':
        token_type = PLUS;
        break;
    case ';':
        token_type = SEMICOLON;
        break;
    case '*':
        token_type = STAR;
        break;
    case '\n':
        token_type = NEWLINE;
        scanner->line++;
        break;
    default:
        // TODO: Implement error handling.
        printf("Unexpected token.\n");
        return;
    }

    // NOTE: The 2nd last two arguments will need fixing.
    // - The 2nd last might be wrong. Since it is a void pointer.
    // To use it might need to do a (char *) on it later.
    // - The last arg just need a way to get that information properly.
    Token token = {token_type, &ch, &ch, scanner->line};
    *(scanner->tokens + NUM_TOKENS) = token;
    NUM_TOKENS++;
}
