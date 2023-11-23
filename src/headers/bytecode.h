#ifndef BYTECODE_H
#define BYTECODE_H

#include <stdio.h>
#include <stdlib.h>

enum OpCode {
    PUSH,
    ADD,
    OpConstant,
} typedef OpCode;

// opcode opcode - The current opcode.
// int* byte - Contains the number of operands, and how many bytes
// an operand is.
typedef struct Instruction {
    OpCode opcode;
    int *operands;
} Instruction;

struct {
    char *name;
    int byte;
    int num_operands;
} typedef inst_info;

extern inst_info inst_mapping[];

void print_inst(Instruction *instruction);
Instruction *new_inst(OpCode opcode, int *operands);

#endif