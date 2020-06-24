#ifndef INVADERS_DI_H
#define INVADERS_DI_H

#include "instruction.h"

class DI: public Instruction {
public:
    DI() = delete;
    ~DI() = default;
    DI(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.interruptEnabled = false;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
