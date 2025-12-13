#ifndef DEFINE_H
#define DEFINE_H

#include <stdint.h>

// Opcodes
typedef enum {
    NOP,
    SPV,
    SMP,
    CPV,
    SMV,
    CMP,
    JMP,
    JNE,
    JEQ,
    RET,
    ADD, SUB,
    INC, DEC
} Opcode;

// Page + offset = 2 bytes
typedef struct {
    uint8_t page;
    uint8_t offset;
} Address;
typedef struct {
    Address source; 
    uint8_t id;
    Address reference;
}Pointer;
// Operand type
typedef enum {
    OP_LIT,     // literal byte
    OP_PTR,     // pointer register index
    OP_ADDR     // 2-byte address
} OperandType;

// Operand stored in bytecode
typedef struct {
    OperandType type;
    union {
        uint8_t literal;
        uint16_t ptr;
        Address address;
    };
} Operand;

// Instruction decoded from bytecode
typedef struct {
    Opcode opcode;
    uint8_t operandCount;
    Operand operands[3];
} Instruction;
typedef struct {
    Instruction* instruction;
    size_t size;
    size_t capacity;
} array_instruction;
#endif
