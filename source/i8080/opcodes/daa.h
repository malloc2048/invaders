#ifndef INVADERS_DAA_H
#define INVADERS_DAA_H

#include "opcode.h"

class DAA: public OpCode {
public:
    DAA() = default;
    ~DAA() = default;
    DAA(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t carry = flags.carry;
        uint8_t lsb = registers.a & 0x0fu;
        if(flags.halfCarry || lsb > 9) {
            registers.a += 6;
        }

        uint8_t msb = registers.a >> 4u;
        if(flags.carry || msb > 9) {
            registers.a += 0x60;
        }
        updateFlags(registers.a);
        flags.halfCarry = (lsb & 0x10u) != 0;
        flags.carry = msb > 9 ? 1 : 0;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
