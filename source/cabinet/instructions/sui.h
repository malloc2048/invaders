#ifndef INVADERS_SUI_H
#define INVADERS_SUI_H

#include "instruction.h"

class SUI: public Instruction {
public:
    SUI() = delete;
    ~SUI() = default;
    SUI(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t diff = registers.a - memory.read_byte(registers.pc.d16);

        flags.halfCarry = (diff & 0x000fu) > (registers.a & 0x0fu) ? 1 : 0;
        updateFlags(diff);
        flags.carry = (diff & 0x100u) != 0 ? 1 : 0;

        registers.a = diff & 0x00ffu;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
