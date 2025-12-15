#ifndef DEFINE_H
#define DEFINE_H

#include <cstdint> // for uint8_t, uint16_t, uint32_t

namespace VM {
    
    // Corrected the enum declaration and added missing commas
    typedef enum {
        NOP = 0, 
        HLT,
        SPV, SMP, CPV,
        ADD, SUB,
        INC, DEC,
        CMP, JMP, JEQ, JNE, JLT, JGT
    } OPTCODE;

    // Corrected spelling of operand types
    typedef enum {
        POINTER,
        immediate_08,
        immediate_16,
        immediate_32
    } OPERANDTYPE;

    // Fixed the union definition and added proper semicolon
    typedef struct {
        OPERANDTYPE type;
        union {
            uint8_t byte;
            uint16_t integer;
            uint32_t address;
        };
    } OPERAND;

    class instruction {
    public:
        OPTCODE optcode = NOP;  // default to NOP
        OPERAND operand;  // Operand struct

        // Fixed function syntax: newexit takes an integer argument (exit code)
        void newexit(int code) {
            // exit cleanup here
            // Example: exit(code); or similar
        }

        // Modified ishalt to handle the "HLT" opcode
        void ishalt() {
            if (optcode == HLT) {
                newexit(0);  // Exit with code 0 if HLT opcode is encountered
            }
        }

        // exec function to handle various opcodes like ADD, etc.
        int exec() {
            switch (optcode) {
                case ADD:
                    // Implement ADD logic here
                    std::cout << "ADD operation\n";
                    return 0;
                case SUB:
                    // Implement SUB logic here
                    std::cout << "SUB operation\n";
                    return 0;
                case INC:
                    // Implement INC logic here
                    std::cout << "INC operation\n";
                    return 0;
                case DEC:
                    // Implement DEC logic here
                    std::cout << "DEC operation\n";
                    return 0;
                case CMP:
                    // Implement CMP logic here
                    std::cout << "CMP operation\n";
                    return 0;
                // Add more cases for other operations
                default:
                    std::cout << "Unknown operation\n";
                    return -1;  // Return -1 if the opcode is unrecognized
            }
        }
    };
}

#endif
