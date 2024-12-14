#include "instructions.h"
#include "bootup.h"
void mov(){
    printf("Here\n" );
    //The target is memory[memory[PC]]
    uint16_t instruction = memory[memory[PC]];
    printf("%d\n",instruction>>8&0b1111);
    memory[instruction>>8&0b1111] = (instruction>>4)&0b1111;
}
void pnt(){
    uint16_t instruction = memory[memory[PC]];
    printf("Printing %d\n",memory[instruction>>8&0b1111]);
}
