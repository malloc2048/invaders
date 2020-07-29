#ifndef INVADERS_RST_H
#define INVADERS_RST_H

#include "instruction.h"

class RST: public Instruction {
public:
    RST() = delete;
    ~RST() = default;
    RST(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t number = (opcode & 0x038u) >> 3u;

        RegisterPair nextAddr{};
        nextAddr.d16 = registers.pc.d16;
        memory.write(registers.sp.d16 - 1, nextAddr.bytes.high);
        memory.write(registers.sp.d16 - 2, nextAddr.bytes.low);
        registers.sp.d16 -= 2;
        registers.pc.d16 = 8 * number;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }

protected:
    void ret() {
        RegisterPair address{};
        address.bytes.low = memory.read_byte(registers.sp.d16);
        address.bytes.high = memory.read_byte(registers.sp.d16 + 1);
        registers.pc.d16 = address.d16;
        registers.sp.d16 += 2;
    }
};

#endif