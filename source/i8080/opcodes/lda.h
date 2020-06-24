#ifndef INVADERS_LDA_H
#define INVADERS_LDA_H

#include "opcode.h"

class LDA: public OpCode {
public:
    LDA() = delete;
    ~LDA() = default;

    LDA(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto address = memory.read_word(registers.pc.d16);
        registers.a = memory.read_byte(address);
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
