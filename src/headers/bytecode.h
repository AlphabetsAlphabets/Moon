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

// char* name - The name of the instruction.
// int byte - The number of bytes the instruction takes. This will limit the size of the operand.
// int max_operands - The maximum number of operands. The length of the instruction.
typedef struct InstructionInfo {
    char *name;
    int byte;
    int max_operands;
} InstructionInfo;

extern InstructionInfo inst_mapping[];

void print_inst(Instruction *instruction);
Instruction *new_inst(OpCode opcode, int *operands);

#endif
