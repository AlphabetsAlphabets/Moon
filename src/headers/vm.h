#ifndef VM_H
#define VM_H

#include "src/headers/bytecode.h"

static int PROGRAMS = 0;

typedef struct VM {
    // the program counter keeps track of the call stack.
    int program_counter;
    // this points to the top of the data stack
    int stack_pointer;
    // This is the data stack.
    int *stack;
    Instruction *call_stack;
} VM;

void runVM(const VM *vm);

#endif
