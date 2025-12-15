#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdlib.h>
#include "../header/definitions.h"
int main(int c ,char** v) {
    VM::instruction virtual_machine;
    virtual_machine.optcode = VM::ADD;
    while (1) {
        
    virtual_machine.exec();
    if (virtual_machine.optcode == VM::SUB) break;
    virtual_machine.optcode = VM::SUB;
    }return 0;
}