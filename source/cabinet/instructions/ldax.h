#ifndef INVADERS_LDAX_H
#define INVADERS_LDAX_H

#include "instruction.h"

class LDAX: public Instruction {
public:
    LDAX() = delete;
    ~LDAX() = default;

    LDAX(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;
        switch(rp) {
            case BC:
                registers.a = memory.read_byte(registers.bc.d16);
                break;
            case DE:
                registers.a = memory.read_byte(registers.de.d16);
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
