#ifndef INVADERS_HLT_H
#define INVADERS_HLT_H

#include "opcode.h"

class HLT: public Instruction {
public:
    HLT() = delete;
    ~HLT() = default;

    HLT(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        registers.halted = true;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
