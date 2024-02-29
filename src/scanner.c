#include "src/headers/scanner.h"
#include "tokens.h"

TokenName token_names[] = {
    [STAR] = {"STAR"},
    [SEMICOLON] = {"SEMICOLON"},
    [PLUS] = {"PLUS"},
    [DIVIDE] = {"DIVIDE"},
    [MINUS] = {"MINUS"},
    [DOT] = {"DOT"},
    [COMMA] = {"COMMA"},
    [RIGHT_BRACE] = {"RIGHT_BRACE"},
    [LEFT_BRACE] = {"LEFT_BRACE"},
    [RIGHT_PAREN] = {"RIGHT_PAREN"},
    [LEFT_PAREN] = {"LEFT_PAREN"},
    [NEWLINE] = {"NEWLINE"},
    [MODULUS] = {"MODULUS"},
    [GREATER_EQUALS] = {"GREATER_EQUALS"},
    [BANG_EQUALS] = {"BANG_EQUALS"},
    [LESS_EQUALS] = {"LESS_EQUALS"},
    [EQUALS_EQUALS] = {"EQUALS_EQUALS"},
    [END_OF_FILE] = {"<<END>>"},
    [COMMENT] = {"COMMENT"},
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

char advance(Scanner *scanner) { return scanner->source[scanner->column++]; }

char peak(Scanner *scanner) {
    char next = scanner->source[scanner->column + 1];
    return next;
}

void identify_token(Scanner *scanner, char *ch) {
    TokenType token_type;
    // NOTE: When updating the switch case
    // update TokenName token_names[] as well.
    char *lexeme = ch;
    switch (*ch) {
    case ' ':
    case '\r':
    case '\t':
        return;
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
        token_type = EQUALS;
        if (peak(scanner) == '=') {
            token_type = EQUALS_EQUALS;
            lexeme = "==";
            advance(scanner);
        }
        break;
    case '!':
        token_type = BANG;
        if (peak(scanner) == '=') {
            lexeme = "!=";
            token_type = BANG_EQUALS;
            advance(scanner);
        }
        break;
    case '>':
        if (peak(scanner) == '=') {
            token_type = GREATER_EQUALS;
            lexeme = ">=";
            advance(scanner);
            break;
        } else {
            printf("Unexpected token: '%s' at %i:%i. Did you mean '>='?\n", ch,
                   scanner->line, scanner->column + 1);
            scanner->has_error = 1;
            return;
        }
    case '<':
        if (peak(scanner) == '=') {
            token_type = LESS_EQUALS;
            lexeme = "<=";
            advance(scanner);
            break;
        } else {
            printf("Unexpected token: '%s' at %i:%i. Did you mean '<='?\n", ch,
                   scanner->line, scanner->column + 1);
            scanner->has_error = 1;
            return;
        }
    case '/':
        if (peak(scanner) == '/') {
            while (advance(scanner) != '\n') {}
            return;
        }

        token_type = COMMENT;
        break;
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

    Token token = {token_type, lexeme, lexeme, scanner->line};
    scanner->tokens[NUM_TOKENS] = token;
    NUM_TOKENS++;
}
