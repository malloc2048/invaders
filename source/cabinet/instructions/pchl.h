#ifndef INVADERS_PCHL_H
#define INVADERS_PCHL_H

#include "instruction.h"

class PCHL: public Instruction {
public:
    PCHL() = delete;
    ~PCHL() = default;
    PCHL(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.pc.d16 = registers.hl.d16;
    }
};
#endif
