#include <stdlib.h>

#include "headers/scanner.h"
// The compiler needs to traverse the AST
// That means we need to get the AST first.
// We get the AST by parsing source code. So that means I need to write a
// parser.
//
// convert them into integers.
// Add them to the constant pool. Then emit OpConstant
// instructions that reference the constants in said pool

int main(void) {
    char *source = "\"\"\"";
    Scanner *scanner = malloc(sizeof(Scanner));
    scanner->source = source;
    scanner->has_error = 0;

    scan(scanner);
    if (!scanner->has_error) {
        print_token(scanner);
    }

    return 0;
}
