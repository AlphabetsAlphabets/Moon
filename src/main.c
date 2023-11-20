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

int find_operand_size(opcode opcode) {
    int byte;
    switch (opcode) {
    case PUSH:
        byte = 1;
        break;
    case ADD:
        byte = 1;
        break;
    case OpConstant:
        byte = 2;
        break;
    }

    return byte;
}

int find_num_operands(opcode opcode) {
    int length;
    switch (opcode) {
    case PUSH:
        length = 1;
        break;

    case ADD:
        length = 2;
        break;
    case OpConstant:
        length = 1;
        break;
    }

    return length;
}

void print_inst(opcode opcode) {
    char *s;
    switch (opcode) {
    case PUSH:
        s = "PUSH";
        break;
    case ADD:
        s = "ADD";
        break;
    case OpConstant:
        s = "OpConstant";
        break;
    }

    int num_operand = find_num_operands(opcode);
    int operand_size = find_operand_size(opcode);
    printf("%s: %i bytes x %i\n", s, operand_size, num_operand);
}

inst *new_inst(opcode opcode) {
    int num_operands;
    inst *instruction;

    instruction = (inst *)malloc(sizeof(inst));
    instruction->opcode = opcode;

    num_operands = find_num_operands(opcode);
    instruction->operands = (int *)malloc(num_operands * sizeof(int));
    return instruction;
}

int main(void) {
    inst *add;
    add = new_inst(OpConstant);
    print_inst(add->opcode);

    return 0;
}
