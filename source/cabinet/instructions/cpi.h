#ifndef INVADERS_CPI_H
#define INVADERS_CPI_H

#include "instruction.h"

class CPI: public Instruction {
public:
    CPI() = delete;
    ~CPI() = default;
    CPI(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t result = registers.a - memory.read_byte(registers.pc.d16);

        updateFlags(result);
        flags.halfCarry = (result & 0x000fu) > (registers.a & 0x0fu) ? 1 : 0;
        flags.carry = (result & 0x0100u) != 0 ? 1 : 0;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
