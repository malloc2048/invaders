#ifndef INVADERS_LDA_H
#define INVADERS_LDA_H

#include "instruction.h"

class LDA: public Instruction {
public:
    LDA() = delete;
    ~LDA() = default;

    LDA(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto address = memory.read_word(registers.pc.d16);
        registers.a = memory.read_byte(address);
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
