#ifndef INVADERS_XCHG_H
#define INVADERS_XCHG_H

#include "opcode.h"

class XCHG: public Instruction {
public:
    XCHG() = delete;
    ~XCHG() = default;
    XCHG(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t hl = registers.hl.d16;
        registers.hl.d16 = registers.de.d16;
        registers.de.d16 = hl;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
