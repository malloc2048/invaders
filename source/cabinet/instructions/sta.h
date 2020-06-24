#ifndef INVADERS_STA_H
#define INVADERS_STA_H

#include "instruction.h"

class STA: public Instruction {
public:
    STA() = delete;
    ~STA() = default;

    STA(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto address = memory.read_word(registers.pc.d16);
        memory.write(address, registers.a);
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
