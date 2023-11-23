#include "headers/bytecode.h"

inst_info inst_mapping[] = {
    // Name, byte, length
    [PUSH] = {"PUSH", 1, 2},
    [ADD] = {"ADD", 2, 2},
    [OpConstant] = {"OpConstant", 2, 1},
};


void print_inst(Instruction *instruction) {
    inst_info info = inst_mapping[instruction->opcode];
    printf("'%s ", info.name);
    for (int i = 0; i < info.num_operands; i++) {
        int operands = instruction->operands[i];
        if (i == info.num_operands - 1) {
            printf("%i", operands);
        } else {
            printf("%i ", operands);
        }
    }

    printf("' - %i bytes x %i operand\n", info.byte, info.num_operands);
}

Instruction *new_inst(OpCode opcode, int *operands) {
    Instruction *instruction;

    instruction = (Instruction *)malloc(sizeof(Instruction));
    instruction->opcode = opcode;

    inst_info info = inst_mapping[opcode];
    int num_operands = info.num_operands;
    instruction->operands = (int *)malloc(num_operands * sizeof(int));
    for (int i = 0; i < num_operands; i++) {
        *(instruction->operands + i) = *(operands + i);
    }

    return instruction;
}
