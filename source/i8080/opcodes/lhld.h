#ifndef INVADERS_LHLD_H
#define INVADERS_LHLD_H

#include "opcode.h"

class LHLD: public OpCode {
public:
    LHLD() = delete;
    ~LHLD() = default;

    LHLD(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        RegisterPair address {};
        address.bytes.low = memory.readByte(registers.pc.d16);
        address.bytes.high = memory.readByte(registers.pc.d16 + 1);
        registers.hl.d16 = memory.readWord(address.d16);
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
