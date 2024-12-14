#include "assembler.h"
#include "hashMap.h"
#include <ctype.h>
int is_whole_number(const char* str) {
    // Handle empty strings
    if (str == NULL || *str == '\0') {
        return -1;
    }

    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return -1;  // Return -1 if any character is not a digit
        }
    }

    // Convert the string to an integer and return it
    return atoi(str);
}
//The assembler will take the file, and process it, returning a stream of pure bytecode
//If that isnt cool, I dont know what is
uint16_t* assembler(char* filename){
    uint16_t bytecodeBuffer[256];
    uint8_t pointer = 0;
    FILE *file = fopen(filename,"r");
    char line[LINESIZE];
    loadTables();//Load lookup table
    while(fgets(line,sizeof(line),file)!=NULL){
        uint16_t instruction;
        int paramLabel = 0;
        //Now we will loop through the line
        char str[8];
        uint8_t strPointer = 0;
        for(uint8_t i = 0;line[i]!='\0';i++){
            if(line[i]==32 || line[i+1] == '\0'){//Space or last in line
                int8_t code = lookup(command_table,str);
                if(code != -1){
                    instruction |= code;
                    continue;
                }
                code = lookup(register_table,str);
                if(code != -1){
                    instruction = instruction << 4;
                    instruction |= code;
                    paramLabel++;
                    continue;
                }
                int num = is_whole_number(str);
                if(num!=-1){
                    instruction = instruction << 4;
                    instruction |= code;
                    paramLabel++;
                    continue;
                }
                else{
                    printf("Invalid Expression");
                    exit(0);
                }
            }
            else{
            str[strPointer] = line[i];
            strPointer++;
            }
            }
            int remainder = 3-paramLabel;
            instruction <<= 4*remainder;
            for(int i=0;i<8;i++){
                str[i] = 0;
            }
            strPointer = 0;
            paramLabel = 0;
            bytecodeBuffer[pointer] = instruction;
            pointer++;
        }
        //Now we will make a new buffer with appropriate size for the buffer
        uint16_t* bytecode = (uint16_t*)malloc(pointer*2);
        for(int i=0;i<pointer;i++){
            *(bytecode+i) = bytecodeBuffer[i];
        }
        return bytecode;
    }
