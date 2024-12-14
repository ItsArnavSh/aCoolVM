#include "vm.h"
#include "bootup.h"
void startExecution(){
    //First we start at the program counter
    //memory[INSTRUCTION]
    void(*opfunc[16])() = {mov_ins,pnt_ins,cpy_ins,and_ins,or_ins,xor_ins,add_ins,sub_ins};
    while(memory[PC]!=codeEndPointer){
        opfunc[memory[memory[PC]]>>12]();
        memory[PC]++;
    }
}
