#ifndef INVADERS_CMC_H
#define INVADERS_CMC_H

#include "opcode.h"

class CMC: public OpCode {
public:
    CMC() = delete;
    ~CMC() = default;
    CMC(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        flags.carry = !flags.carry;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
