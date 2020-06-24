#ifndef INVADERS_CMA_H
#define INVADERS_CMA_H

#include "instruction.h"

class CMA: public Instruction {
public:
    CMA() = delete;
    ~CMA() = default;
    CMA(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.a ^= 0xffu;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
