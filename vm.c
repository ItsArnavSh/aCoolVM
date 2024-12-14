#include "vm.h"
#include "bootup.h"
void startExecution(){
    //First we start at the program counter
    //memory[INSTRUCTION]
    void(*opfunc[16])() = {mov,pnt};
    opfunc[memory[INSTRUCTION]>>12]();
}
