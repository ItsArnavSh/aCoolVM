#include "bootup.h"
uint16_t memory[MEM_SIZE];
void bootupVM(){
    for(int i=0;i<10;i++)
        memory[i] = 0;
    memory[SP] = MEM_SIZE-1;//The first place on the stack, we will grow upwards
    memory[PC] = INSTRUCTION;//Start executing the bootup code at startup
}
