#include "bytecode.h"

#include <stdio.h>
#include <stdlib.h>

void print_inst(inst *instruction) {
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

inst *new_inst(opcode opcode, int *operands) {
    inst *instruction;

    instruction = (inst *)malloc(sizeof(inst));
    instruction->opcode = opcode;

    inst_info info = inst_mapping[opcode];
    int num_operands = info.num_operands;
    instruction->operands = (int *)malloc(num_operands * sizeof(int));
    for (int i = 0; i < num_operands; i++) {
        *(instruction->operands + i) = *(operands + i);
    }

    return instruction;
}
