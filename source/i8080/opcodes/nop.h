#ifndef INVADERS_NOP_H
#define INVADERS_NOP_H

#include "opcode.h"

class NOP: public OpCode {
public:
    NOP() = delete;
    ~NOP() = default;
    NOP(Flags& flags, Memory& memory, Registers& registers) : OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
