#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include "common.h"
#include "hashMap.h"
#include "debugger.h"
#define LINESIZE 128
uint16_t* assembler(char* filename);
typedef struct instruction{
    //An instruction can be broken down into its OPCODE, PARAM1, PARAM2, PARAM3
    //Our task is to safely decode the statement into this struct, which will be later fed into bytecode stream
    uint8_t opcode : 4;
    uint8_t param1 : 4;
    uint8_t param2 : 4;
    uint8_t param3 : 4;
    //Here we are using bitfields
    //They will first tell the underlying ds is ui8, then pack 2 of these into one, as we need only 4
}instruction;
#endif
