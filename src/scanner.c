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
    [END_OF_FILE] = {"<<END>>"},
};

void print_token(Scanner *scanner) {
    Token token = *scanner->tokens;
    for (int i = 0; token.type != END_OF_FILE; i++) {
        token = scanner->tokens[i];
        char *name = token_names[token.type].name;
        char *lexeme = token.lexeme;
        printf("%s ('%c') at line %i\n", name, *lexeme, token.line);
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
        // This is supposed to be a character
        // but because the type of ch is char*
        // it takes the whole thing as a string.
        *ch = scanner->source[*column];
        identify_token(scanner, ch);
    }

    Token eof_token = {END_OF_FILE, "EOF", "EOF", *line};
    scanner->tokens[NUM_TOKENS++] = eof_token;
}

// FIXME:
// `char *ch` is a string and not a character. So the
// entire source is passed in, not the specific character.
// So the lexeme would be the entire source.
// That is until the iterator moves forward and omits the previous
// character until the string is finished.
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
    case '\n':
        token_type = NEWLINE;
        scanner->line++;
        break;
    default:
        // TODO: Implement error handling.
        printf("Unexpected token: '%s' at line %i.\n", ch, scanner->line);
        scanner->has_error = 1;
        return;
    }

    Token token = {token_type, ch, ch, scanner->line};
    scanner->tokens[NUM_TOKENS] = token;
    NUM_TOKENS++;
}
