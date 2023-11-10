#include <stdio.h>
#include <stdlib.h>

static int PROGRAMS = 0;

// You can't store values in C through an enum like Data(int)
// Next best option is to have a struct that stores the enum
// you want and a field to store said data.
enum OpCode {
    SET,
    ADD,
} typedef opcode;

struct Instruction {
    opcode op_code;
    int data;
    int is_value;
} typedef instruction;

instruction new_instruction(opcode op_code, int data, int is_value) {
    instruction instruction = {op_code, data, is_value};

    return instruction;
}

struct VM {
    // the program counter keeps track of the call stack.
    int program_counter;
    // this points to the top of the data stack
    int stack_pointer;
    // This is the data stack.
    int *stack;
    instruction *call_stack;
} typedef VM;

void runVM(const VM *vm) {
    int program_counter = vm->program_counter;
    int stack_pointer = vm->stack_pointer;

    while (program_counter < PROGRAMS) {
        instruction curInstruction = vm->call_stack[program_counter];
        int op_code = curInstruction.op_code;

        if (op_code == 0) { // SET
            vm->stack[stack_pointer] = curInstruction.data;
        } else if (op_code == 1) {                 // ADD
            int v1 = vm->stack[stack_pointer - 2]; // the 1st value
            int v2 = vm->stack[stack_pointer - 1]; // the 2st value
            // Store it at the top of the stack.
            vm->stack[stack_pointer] = v1 + v2;
        }

        stack_pointer++;
        program_counter++;
    }
}

int main(int argc, char **argv) {
    instruction set, add, set2;
    // 1 + 2
    // The top of the stack should be 3
    set = new_instruction(SET, 1, 1);
    set2 = new_instruction(SET, 2, 1);
    add = new_instruction(ADD, 0, 0);

    instruction program[] = {set, set2, add};
    PROGRAMS = sizeof(program) / sizeof(instruction);

    VM *vm = malloc(sizeof(VM));

    vm->program_counter = 0;
    vm->stack_pointer = 0;

    int *p;
    p = (int *)malloc(2 * PROGRAMS);
    if (!p) {
        printf("Out of memory.\n");
        return 1;
    }

    vm->stack = p;

    instruction *q;
    q = (instruction *)malloc(PROGRAMS);
    if (!q) {
        printf("Out of memory.\n");
        return 1;
    }

    vm->call_stack = q;
    vm->call_stack = program;

    runVM(vm);
    printf("%i\n", *vm->stack);

    return 0;
}
