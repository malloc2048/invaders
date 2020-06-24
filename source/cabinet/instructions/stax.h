#ifndef INVADERS_STAX_H
#define INVADERS_STAX_H

#include "instruction.h"

class STAX: public Instruction {
public:
    STAX() = delete;
    ~STAX() = default;

    STAX(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        switch(rp) {
            case BC:
                memory.write(registers.bc.d16, registers.a);
                break;
            case DE:
                memory.write(registers.de.d16, registers.a);
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
