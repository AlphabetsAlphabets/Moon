#include "headers/vm.h"

int main(void) {
    Instruction *instruction;
    int operands[] = {65535};
    instruction = new_inst(OpConstant, operands);
    print_inst(instruction);

    // The compiler needs to traverse the AST
    // That means we need to get the AST first.
    // We get the AST by parsing source code. So that means I need to write a parser.
    //
    // convert them into integers.
    // Add them to the constant pool. Then emit OpConstant
    // instructions that reference the constants in said pool

    return 0;
}
