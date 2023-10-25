#include <stdio.h>

// While not an instruction I need a method to store the value of something for an operation.
// Something like Value(int) or Data(int) 
enum Instruction { ADD, SUB, MULTI, DIVIDE } typedef instruction;

struct VM {
  int program_counter;
  // I need to determine the size of the array based on the number of
  // instructions I have. Which means this value needs to be set **AFTER** I
  // identify how many instructions there are.
  instruction stack[50];
} typedef VM;

int main(int argc, char **argv) {
  instruction program[] = {ADD, SUB};
  printf("Hello World!");
  return 0;
}
