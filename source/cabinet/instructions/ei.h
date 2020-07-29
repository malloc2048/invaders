#ifndef INVADERS_EI_H
#define INVADERS_EI_H

#include "instruction.h"

class EI: public Instruction {
public:
    EI() = delete;
    ~EI() = default;
    EI(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.interruptEnabled = true;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif