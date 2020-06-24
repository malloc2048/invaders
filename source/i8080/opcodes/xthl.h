#ifndef INVADERS_XTHL_H
#define INVADERS_XTHL_H

#include "opcode.h"

class XTHL: public OpCode {
public:
    XTHL() = delete;
    ~XTHL() = default;
    XTHL(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto value = memory.read_word(registers.sp.d16);
        memory.write(registers.sp.d16, registers.hl.bytes.low);
        memory.write(registers.sp.d16 + 1, registers.hl.bytes.high);
        registers.hl.d16 = value;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
