#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum {
    SPV, // set pointer Value <Px> <byte>
    SMP, // set memory pointer <Px> <32bit> 
    CPV, // copy pointer  value <Px> <Py>
    SMV, // set memory value <32bit> <byte>
    ADD, // add <Pz> <Px> <Py>
    SUB, // subract same as add
    INC, // increment <Px>
    DEC, // decriment <Px>
    CMP, // compare <Px> <Py>
    JNE, // jump if not equal <address> 
    JEQ, // jump if equal  same
    JMP, // jump  same
    CALL,// jump with return <address> < return> 
    RET // return <return>
} Optcode;
typedef struct {
    uint16_t page;
    uint16_t offset;
} Address;
typedef struct {
    uint8_t id;
    Address storage;
    Address address;
    union {
    uint8_t byte;
    uint16_t integer;
};
} Pointer;
typedef struct {
    Optcode optcode;
    union {
        Address address[3];
        Pointer pointer[3];
        uint8_t byte[3];
    } ; 
} Instruction;
int main() {
    printf("this is a build is %d lines long\n",__LINE__);
    
    return 0;
}