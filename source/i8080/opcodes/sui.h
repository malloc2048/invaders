#ifndef INVADERS_SUI_H
#define INVADERS_SUI_H

#include "opcode.h"

class SUI: public OpCode {
public:
    SUI() = delete;
    ~SUI() = default;
    SUI(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t diff = registers.a - memory.readByte(registers.pc.d16);

        flags.halfCarry = (diff & 0x000fu) > (registers.a & 0x0fu) ? 1 : 0;
        updateFlags(diff);
        flags.carry = (diff & 0x100u) != 0 ? 1 : 0;

        registers.a = diff & 0x00ffu;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
