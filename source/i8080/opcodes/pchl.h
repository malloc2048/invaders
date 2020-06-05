#ifndef INVADERS_PCHL_H
#define INVADERS_PCHL_H

#include "opcode.h"

class PCHL: public OpCode {
public:
    PCHL() = delete;
    ~PCHL() = default;
    PCHL(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.pc.d16 = registers.hl.d16;
    }
};
#endif
