#ifndef INVADERS_STC_H
#define INVADERS_STC_H

#include "opcode.h"

class STC: public OpCode {
public:
    STC() = delete;
    ~STC() = default;

    STC(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        flags.carry = 1;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
