#ifndef INVADERS_XRI_H
#define INVADERS_XRI_H

#include "opcode.h"

class XRI: public OpCode {
public:
    XRI() = delete;
    ~XRI() = default;
    XRI(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t result = registers.a ^memory.readByte(registers.pc.d16);
        updateFlags(result);
        flags.carry = 0;
        flags.halfCarry = 0;
        registers.a = result & 0x00ffu;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif