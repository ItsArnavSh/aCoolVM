#include "vm.h"
#include "bootup.h"
void startExecution(){
    //First we start at the program counter
    //memory[INSTRUCTION]
    void(*opfunc[2])() = {mov,pnt};
    while(memory[PC]!=codeEndPointer){
        opfunc[memory[memory[PC]]>>12]();
        printf("Executed Line %d %d\n",memory[PC],codeEndPointer);
        memory[PC]++;
    }
}
