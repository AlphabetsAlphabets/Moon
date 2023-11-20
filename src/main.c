#include <stdio.h>
#include <stdlib.h>

enum opcode {
    PUSH,
    ADD,
    OpConstant,
} typedef opcode;

// opcode opcode - The current opcode.
// int* byte - Contains the number of operands, and how many bytes
// an operand is.
struct instruction {
    opcode opcode;
    int *operands;
} typedef inst;

struct instruction_info {
    char *name;
    int byte;
    int num_operands;
} typedef inst_info;

static inst_info instructions[] = {
    // Name, byte, length
    [PUSH] = {"PUSH", 1, 2},
    [ADD] = {"ADD", 2, 2},
    [OpConstant] = {"OpConstant", 2, 1},
};

void print_inst(opcode opcode) {
    inst_info info = instructions[opcode];
    printf("%s: %i bytes x %i\n", info.name, info.byte, info.num_operands);
}

inst *new_inst(opcode opcode) {
    inst *instruction;

    instruction = (inst *)malloc(sizeof(inst));
    instruction->opcode = opcode;

    inst_info info = instructions[opcode];
    instruction->operands = (int *)malloc(info.num_operands * sizeof(int));

    return instruction;
}

int main(void) {
    // If OpConstant is the instruction
    // 1. The opcode is opconstant
    // 2. The number of operands is 1
    // 3. The size of the operand is 2 bytes.

    inst *add;
    add = new_inst(PUSH);
    print_inst(add->opcode);
    *add->operands = 1;

    return 0;
}
