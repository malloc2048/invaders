#ifndef INVADERS_SPHL_H
#define INVADERS_SPHL_H

#include "opcode.h"

class SPHL: public OpCode {
public:
    SPHL() = delete;
    ~SPHL() = default;
    SPHL(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.sp.d16 = registers.hl.d16;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
