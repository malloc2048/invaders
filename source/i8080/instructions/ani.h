#ifndef INVADERS_ANI_H
#define INVADERS_ANI_H

#include "opcode.h"

class ANI: public Instruction {
public:
    ANI() = delete;
    ~ANI() = default;
    ANI(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t result = registers.a & memory.read_byte(registers.pc.d16);

        updateFlags(result);
        flags.halfCarry = 0;
        flags.carry = 0;
        registers.a = result & 0x00ffu;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};

#endif
