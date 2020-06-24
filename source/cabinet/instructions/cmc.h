#ifndef INVADERS_CMC_H
#define INVADERS_CMC_H

#include "instruction.h"

class CMC: public Instruction {
public:
    CMC() = delete;
    ~CMC() = default;
    CMC(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        flags.carry = !flags.carry;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
