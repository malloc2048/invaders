#ifndef INVADERS_SPHL_H
#define INVADERS_SPHL_H

#include "instruction.h"

class SPHL: public Instruction {
public:
    SPHL() = delete;
    ~SPHL() = default;
    SPHL(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.sp.d16 = registers.hl.d16;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
