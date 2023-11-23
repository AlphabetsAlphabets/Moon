#include "src/headers/bytecode.h"

// Contains
// - Name of the opcode.
// - Number of bytes the instruction takes.
// - Maximum number of operands.
InstructionInfo inst_mapping[] = {
    // Name, byte, number of operands
    [ADD] = {"ADD", 2, 2},
    [OpConstant] = {"OpConstant", 2, 1},
};

void print_inst(Instruction *instruction) {
    InstructionInfo info = inst_mapping[instruction->opcode];
    printf("'%s ", info.name);
    for (int i = 0; i < info.max_operands; i++) {
        int operands = instruction->operands[i];
        if (i == info.max_operands - 1) {
            printf("%i", operands);
        } else {
            printf("%i ", operands);
        }
    }

    printf("' - %i bytes x %i operand\n", info.byte, info.max_operands);
}

Instruction *new_inst(OpCode opcode, int *operands) {
    Instruction *instruction;

    instruction = (Instruction *)malloc(sizeof(Instruction));
    instruction->opcode = opcode;

    InstructionInfo info = inst_mapping[opcode];
    int num_operands = info.max_operands;
    instruction->operands = (int *)malloc(num_operands * sizeof(int));
    for (int i = 0; i < num_operands; i++) {
        *(instruction->operands + i) = *(operands + i);
    }

    return instruction;
}
