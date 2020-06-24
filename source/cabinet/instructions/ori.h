#ifndef INVADERS_ORI_H
#define INVADERS_ORI_H

#include "instruction.h"

class ORI: public Instruction {
public:
    ORI() = delete;
    ~ORI() = default;
    ORI(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t result = registers.a | memory.read_byte(registers.pc.d16);
        updateFlags(result);
        flags.carry = 0;
        flags.halfCarry = 0;
        registers.a = result & 0x00ffu;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};

#endif
