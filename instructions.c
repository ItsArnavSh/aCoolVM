#include "instructions.h"
#include "bootup.h"
void mov_ins(){
    //The target is memory[memory[PC]]
    uint16_t instruction = memory[memory[PC]];
    memory[instruction>>8&0b1111] = (instruction>>4)&0b1111;
}
void pnt_ins(){
    uint16_t instruction = memory[memory[PC]];
    printf("Printing %d\n",memory[instruction>>8&0b1111]);
}
void cpy_ins(){//Copy the right's value to left
    uint16_t instruction = memory[memory[PC]];
    memory[instruction>>8&0b1111] = memory[(instruction>>4)&0b1111];
}
//All the binary operators save their results in R6...No specific reason
void and_ins(){
    uint16_t instruction = memory[memory[PC]];
    memory[6] = memory[instruction>>8&0b1111]&memory[instruction>>4&0b1111];
}
void or_ins(){
    uint16_t instruction = memory[memory[PC]];
    memory[6] = memory[instruction>>8&0b1111]|memory[instruction>>4&0b1111];
}
void xor_ins(){
    uint16_t instruction = memory[memory[PC]];
    memory[6] = memory[instruction>>8&0b1111]^memory[instruction>>4&0b1111];
}
void add_ins(){
    uint16_t instruction = memory[memory[PC]];
    memory[6] = memory[instruction>>8&0b1111]+memory[instruction>>4&0b1111];
}
void sub_ins(){
    uint16_t instruction = memory[memory[PC]];
    memory[6] = memory[instruction>>8&0b1111]-memory[instruction>>4&0b1111];
}
