#include "assembler.h"
#include "common.h"
#include "bootup.h"
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
    printf("The length of the code is: %d\n",bytecode[0]);
    for(int i=1;i<bytecode[0];i++){
        print_binary(bytecode[i]);
    }
    //loadProgram(bytecode);
}
