#ifndef INVADERS_INSTRUCTION_H
#define INVADERS_INSTRUCTION_H

#include "hardware/constants.h"
#include "operations/operation.h"

namespace hardware {
    struct Instruction {
        byte size;
        byte cycles;
        byte opcode;
        std::string mnemonic;
        Operation* operation;
    };
}
#endif
