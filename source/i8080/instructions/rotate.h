#ifndef INVADERS_ROTATE_H
#define INVADERS_ROTATE_H

#include "opcode.h"

class Rotate: public Instruction {
public:
    Rotate() = delete;
    ~Rotate() = default;

    Rotate(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        switch(opcode) {
            case 0x07:  // RLC
                flags.carry = registers.a >> 7u;
                registers.a = registers.a << 0x01u | flags.carry;
                break;
            case 0x0f:  // RRC
                flags.carry = registers.a & 0x01u;
                registers.a = (registers.a >> 0x01u) | (flags.carry << 7u);
                break;
            case 0x17: { // RAL
                uint8_t carry = flags.carry;
                flags.carry = registers.a >> 7u;
                registers.a = (registers.a << 1u) | carry;
                break;
            }
            case 0x1f: { // RAR
                uint8_t carry = flags.carry;
                flags.carry = registers.a & 1u;
                registers.a = (registers.a >> 1u) | carry << 7u;
                break;
            }
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
