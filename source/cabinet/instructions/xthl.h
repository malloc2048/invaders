#ifndef INVADERS_XTHL_H
#define INVADERS_XTHL_H

#include "instruction.h"

class XTHL: public Instruction {
public:
    XTHL() = delete;
    ~XTHL() = default;
    XTHL(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto value = memory.read_word(registers.sp.d16);
        memory.write(registers.sp.d16, registers.hl.bytes.low);
        memory.write(registers.sp.d16 + 1, registers.hl.bytes.high);
        registers.hl.d16 = value;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif