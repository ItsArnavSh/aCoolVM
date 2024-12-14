#include "bootup.h"
uint16_t memory[MEM_SIZE];
uint16_t codeEndPointer;
void bootupVM(){
    for(int i=0;i<10;i++)
        memory[i] = 0;
    memory[SP] = MEM_SIZE-1;//The first place on the stack, we will grow upwards
    memory[PC] = INSTRUCTION;//Start executing the bootup code at startup
}
void loadProgram(uint16_t *bytecode){
    for(int i=1;i<bytecode[0];i++){
        memory[PC+i] = bytecode[i];
    }
    codeEndPointer = bytecode[0]+PC;
    printf("Data Loaded into memory\n");
}
