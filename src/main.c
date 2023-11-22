#include "bytecode.h"

int main(void) {
    inst *instruction;
    int operands[] = {65535};
    instruction = new_inst(OpConstant, operands);
    print_inst(instruction);
    // The compiler needs to traverse the AST
    // convert them into integers.
    // Add them to the constant pool. Then emit OpConstant
    // instructions that reference the constants in said pool

    return 0;
}
