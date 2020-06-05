#ifndef INVADERS_DI_H
#define INVADERS_DI_H

#include "opcode.h"

class DI: public OpCode {
public:
    DI() = delete;
    ~DI() = default;
    DI(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.interruptEnabled = false;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
