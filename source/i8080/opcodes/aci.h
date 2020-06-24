#ifndef INVADERS_ACI_H
#define INVADERS_ACI_H

#include "opcode.h"

class ACI: public OpCode {
public:
    ACI() = delete;
    ~ACI() = default;
    ACI(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint16_t sum = registers.a + memory.read_byte(registers.pc.d16) + flags.carry;

        updateFlags(sum);
        flags.halfCarry = (registers.a & 0x0fu) > (sum & 0x000fu) ? 1 : 0;
        flags.carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers.a = sum & 0x00ffu;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
