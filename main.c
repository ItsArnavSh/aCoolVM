#include "assembler.h"
#include "common.h"
#include "bootup.h"
#include "vm.h"
#include <stdint.h>
//Now we will

int main(int argc, char** argv){
    bootupVM();
    //Now we will load the asm instruction from the file
    if(argc!=2){
        printf("Incorrect Code");
        exit(0);
    }
    uint16_t* bytecode = assembler(argv[1]);
    loadProgram(bytecode);//Now the bytecode has been loaded into the memory
    startExecution();
}
