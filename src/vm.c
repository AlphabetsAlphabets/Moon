#include "src/headers/vm.h"

void runVM(const VM *vm) {
    int program_counter = vm->program_counter;
    int stack_pointer = vm->stack_pointer;

    while (program_counter < PROGRAMS) {
        Instruction curInstruction = vm->call_stack[program_counter];
        int op_code = curInstruction.opcode;

        // TODO: Will need to update this logic to adapt to an array of operands.
        if (op_code == 0) { // SET
        } else if (op_code == 1) {               // ADD
        } else if (op_code == 2) {               // MINUS
        }

        stack_pointer++;
        program_counter++;
    }
}
