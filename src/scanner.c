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
    [MODULUS] = {"MODULUS"},
    [END_OF_FILE] = {"<<END>>"},
};

void print_token(Scanner *scanner) {
    Token token = *scanner->tokens;
    for (int i = 0; token.type != END_OF_FILE; i++) {
        token = scanner->tokens[i];
        char *name = token_names[token.type].name;
        printf("%s ('%s') at line %i\n", name, token.lexeme, token.line);
    }
}

void scan(Scanner *scanner) {
    // Initialise the scanner
    int length_of_src = strlen(scanner->source);
    scanner->tokens = malloc(sizeof(Token) * (length_of_src + 1));

    int *line = &scanner->line;
    *line = 1;

    int *column = &scanner->column;
    *column = 0;
    // NOTE: Maybe try out ch **ch instead.
    // TODO: Make sure to do null checks for all
    // mallocs, callocs, etc. if mem == NULL

    for (; *column < length_of_src; (*column)++) {
        char *ch = malloc(sizeof(char));
        *ch = scanner->source[*column];
        identify_token(scanner, ch);
    }

    Token eof_token = {END_OF_FILE, "<<END>>", "<<END>>", *line};
    scanner->tokens[NUM_TOKENS++] = eof_token;
}

char advance(Scanner *scanner) { return *(scanner->source++); }

char peak(Scanner *scanner) {
    char next = *(scanner->source++);
    scanner->source--;
    return next;
}

void identify_token(Scanner *scanner, char *ch) {
    TokenType token_type;
    // NOTE: When updating the switch case
    // update TokenName token_names[] as well.
    switch (*ch) {
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
    case '=':
        switch (peak(scanner)) {
        case '=':
            token_type = EQUALS_EQUALS;
            advance(scanner);
            break;
        default:
            token_type = EQUALS;
        }
    case '!':
        switch (peak(scanner)) {
        case '=':
            token_type = BANG_EQUALS;
            advance(scanner);
            break;
        default:
            token_type = BANG;
        }
    case '>':
        switch (peak(scanner)) {
        case '=':
            token_type = BANG_EQUALS;
            advance(scanner);
            break;
        default:
            printf("Unexpected token: '%s' at %i:%i. Did you mean '>='?\n", ch,
                   scanner->line, scanner->column + 1);
            scanner->has_error = 1;
            return;
        }
    case '<':
        switch (peak(scanner)) {
        case '=':
            token_type = LESS_EQUALS;
            advance(scanner);
            break;
        default:
            printf("Unexpected token: '%s' at %i:%i. Did you mean '<='?\n", ch,
                   scanner->line, scanner->column + 1);
            scanner->has_error = 1;
            return;
        }
    case '\n':
        token_type = NEWLINE;
        scanner->line++;
        break;
    case '%':
        token_type = MODULUS;
        break;
    default:
        printf("Unexpected token: '%s' at %i:%i.\n", ch, scanner->line,
               scanner->column + 1);
        scanner->has_error = 1;
        return;
    }

    Token token = {token_type, ch, ch, scanner->line};
    scanner->tokens[NUM_TOKENS] = token;
    NUM_TOKENS++;
}
