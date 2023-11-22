#ifndef BYTECODE_H
#define BYTECODE_H

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

inst_info inst_mapping[] = {
    // Name, byte, length
    [PUSH] = {"PUSH", 1, 2},
    [ADD] = {"ADD", 2, 2},
    [OpConstant] = {"OpConstant", 2, 1},
};

void print_inst(inst *instruction);
inst *new_inst(opcode opcode, int *operands);

#endif
