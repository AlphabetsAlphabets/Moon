#include "headers/vm.h"

void runVM(const VM *vm) {
    int program_counter = vm->program_counter;
    int stack_pointer = vm->stack_pointer;

    while (program_counter < PROGRAMS) {
        Instruction curInstruction = vm->call_stack[program_counter];
        int op_code = curInstruction.opcode;

        // TODO: Will need to update this logic to adapt to an array of operands.
        if (op_code == 0) { // SET
            vm->stack[stack_pointer] = curInstruction.data;
        } else if (op_code == 1) {               // ADD
            int v1 = vm->stack[--stack_pointer]; // the 1st value
            int v2 = vm->stack[--stack_pointer]; // the 2st value
            // Store it at the top of the stack.
            vm->stack[stack_pointer] = v1 + v2;
        } else if (op_code == 2) {               // MINUS
            int v1 = vm->stack[--stack_pointer]; // the 1st value
            int v2 = vm->stack[--stack_pointer]; // the 2st value
            // Store it at the top of the stack.
            vm->stack[stack_pointer] = v2 - v1;
        }

        stack_pointer++;
        program_counter++;
    }
}