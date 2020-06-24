#ifndef INVADERS_INX_H
#define INVADERS_INX_H

#include "instruction.h"

class INX: public Instruction {
public:
    INX() = delete;
    ~INX() = default;

    INX(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        switch(rp) {
            case BC: registers.bc.d16 += 1; break;
            case DE: registers.de.d16 += 1; break;
            case HL: registers.hl.d16 += 1; break;
            case SP: registers.sp.d16 += 1; break;
            default: break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
