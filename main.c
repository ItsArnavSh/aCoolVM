#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "bootup.h"
#include "bootup.h"
//Now we will

int main(int argc, char** argv){
    bootupVM();
    //Now we will load the asm instruction from the file
    if(argc!=2){
        printf("Incorrect Code");
        exit(0);
    }
    loadIntoMemory(asmParser(argv));
}
