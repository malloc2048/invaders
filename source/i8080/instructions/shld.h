#ifndef INVADERS_SHLD_H
#define INVADERS_SHLD_H

#include "opcode.h"

class SHLD: public Instruction {
public:
    SHLD() = delete;
    ~SHLD() = default;
    SHLD(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        RegisterPair address {};
        address.bytes.low = memory.read_byte(registers.pc.d16);
        address.bytes.high = memory.read_byte(registers.pc.d16 + 1);
        memory.write(address.d16, registers.hl.bytes.low);
        memory.write(address.d16 + 1, registers.hl.bytes.high);
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
