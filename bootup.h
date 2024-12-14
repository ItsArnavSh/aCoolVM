#ifndef BOOTUP_H
#define BOOTUP_H
#include "common.h"
#define MEM_SIZE 65535
//10 Registers, 8 General, and last 2 for PC and SP
// Registers
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define PC 8   // Program Counter
#define SP 9   // Stack Pointer
//From there we will have the stack starting
#define INSTRUCTION 9
extern uint16_t memory[MEM_SIZE];
extern uint16_t codeEndPointer;
void bootupVM();
void loadProgram(uint16_t* bytecode);
#endif
