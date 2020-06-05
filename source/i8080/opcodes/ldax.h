#ifndef INVADERS_LDAX_H
#define INVADERS_LDAX_H

#include "opcode.h"

class LDAX: public OpCode {
public:
    LDAX() = delete;
    ~LDAX() = default;

    LDAX(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;
        switch(rp) {
            case BC:
                registers.a = memory.readByte(registers.bc.d16);
                break;
            case DE:
                registers.a = memory.readByte(registers.de.d16);
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
