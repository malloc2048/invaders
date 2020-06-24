#ifndef INVADERS_STC_H
#define INVADERS_STC_H

#include "instruction.h"

class STC: public Instruction {
public:
    STC() = delete;
    ~STC() = default;

    STC(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        flags.carry = 1;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
