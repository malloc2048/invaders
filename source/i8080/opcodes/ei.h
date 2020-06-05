#ifndef INVADERS_EI_H
#define INVADERS_EI_H

#include "opcode.h"

class EI: public OpCode {
public:
    EI() = delete;
    ~EI() = default;
    EI(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.interruptEnabled = true;
        registers.interruptDelay = 1;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
