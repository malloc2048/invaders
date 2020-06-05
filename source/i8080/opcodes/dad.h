#ifndef INVADERS_DAD_H
#define INVADERS_DAD_H

#include "opcode.h"

class DAD: public OpCode {
public:
    DAD() = default;
    ~DAD() = default;
    DAD(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint32_t sum;
        auto rp = (opcode & 0x30u) >> 4u;

        switch(rp) {
            case BC:
                sum = registers.hl.d16 + registers.bc.d16;
                break;
            case DE:
                sum = registers.hl.d16 + registers.de.d16;
                break;
            case HL:
                sum = registers.hl.d16 + registers.hl.d16;
                break;
            case SP:
                sum = registers.hl.d16 + registers.sp.d16;
                break;
            default:
                sum = registers.hl.d16;
                break;
        }
        registers.hl.d16 = sum & 0x0000ffffu;
        flags.carry = (sum & 0x10000u) != 0 ? 1 : 0;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
