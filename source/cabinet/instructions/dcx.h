#ifndef INVADERS_DCX_H
#define INVADERS_DCX_H

#include "instruction.h"

class DCX: public Instruction {
public:
    DCX() = delete;
    ~DCX() = default;

    DCX(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint8_t value;
        switch(rp) {
            case BC:
                registers.bc.d16 -= 1;
                break;
            case DE:
                registers.de.d16 -= 1;
                break;
            case HL:
                registers.hl.d16 -= 1;
                break;
            case SP:
                registers.sp.d16 -= 1;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif