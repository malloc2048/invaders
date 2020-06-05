#ifndef INVADERS_STA_H
#define INVADERS_STA_H

#include "opcode.h"

class STA: public OpCode {
public:
    STA() = delete;
    ~STA() = default;

    STA(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto address = memory.readWord(registers.pc.d16);
        memory.write(address, registers.a);
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
