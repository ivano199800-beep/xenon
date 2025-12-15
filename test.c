#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    SPV, ADD, INC, HLT
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
        Pointer pointer[3];
        uint8_t byte[3];
    };
} Instruction;

typedef struct {
    bool end;
} Flag;

typedef struct {
    Instruction instr;
    Flag flag;
    Pointer mp[4]; // 4 pointers for this tiny VM
} GLOBAL;

void execute(GLOBAL* vm, Instruction instr) {
    switch(instr.optcode) {
        case SPV: {
            uint8_t id = instr.pointer[0].id;
            uint8_t val = instr.byte[0];
            vm->mp[id].integer = val; // set pointer value
            printf("SPV: mp[%d] = %d\n", id, vm->mp[id].integer);
            break;
        }
        case ADD: {
            uint8_t id_z = instr.pointer[0].id;
            uint8_t id_x = instr.pointer[1].id;
            uint8_t id_y = instr.pointer[2].id;
            vm->mp[id_z].integer = vm->mp[id_x].integer + vm->mp[id_y].integer;
            printf("ADD: mp[%d] = mp[%d] + mp[%d] = %d\n",
                   id_z, id_x, id_y, vm->mp[id_z].integer);
            break;
        }
        case INC: {
            uint8_t id = instr.pointer[0].id;
            vm->mp[id].integer++;
            printf("INC: mp[%d] = %d\n", id, vm->mp[id].integer);
            break;
        }
        case HLT:
            vm->flag.end = true;
            printf("HLT encountered. Stopping VM.\n");
            break;
    }
}

int main() {
    // allocate VM
    GLOBAL* VM = malloc(sizeof(GLOBAL));
    if (!VM) return 1;
    VM->flag.end = false;

    // Initialize pointers
    for (int i = 0; i < 4; i++) VM->mp[i].integer = 0;

    // Example program: set mp[0]=5, mp[1]=10, mp[2]=mp[0]+mp[1], inc mp[2], halt
    Instruction program[] = {
        { .optcode = SPV, .pointer = {{.id=0}}, .byte = {5} },
        { .optcode = SPV, .pointer = {{.id=1}}, .byte = {10} },
        { .optcode = ADD, .pointer = {{.id=2},{.id=0},{.id=1}} },
        { .optcode = INC, .pointer = {{.id=2}} },
        { .optcode = HLT }
    };

    int ip = 0;
    while (!VM->flag.end) {
        execute(VM, program[ip]);
        ip++;
    }

    free(VM);
    return 0;
}
