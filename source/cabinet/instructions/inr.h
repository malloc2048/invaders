#ifndef INVADERS_INR_H
#define INVADERS_INR_H

#include "instruction.h"

class INR: public Instruction {
public:
    INR() = delete;
    ~INR() = default;

    INR(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto r = (opcode & 0x38u) >> 3u;

        uint8_t value;
        switch(r) {
            case B:
                value = registers.bc.bytes.high + 1;
                registers.bc.bytes.high = value;
                break;
            case C:
                value = registers.bc.bytes.low + 1;
                registers.bc.bytes.low = value;
                break;
            case D:
                value = registers.de.bytes.high + 1;
                registers.de.bytes.high = value;
                break;
            case E:
                value = registers.de.bytes.low + 1;
                registers.de.bytes.low = value;
                break;
            case H:
                value = registers.hl.bytes.high + 1;
                registers.hl.bytes.high = value;
                break;
            case L:
                value = registers.hl.bytes.low + 1;
                registers.hl.bytes.low = value;
                break;
            case M:
                value = memory.read_byte(registers.hl.d16) + 1;
                memory.write(registers.hl.d16, value);
                break;
            case A:
                value = registers.a + 1;
                registers.a = value;
                break;
            default:
                break;
        }

        updateFlags(value);
        flags.halfCarry = (value & 0xffu) == 0;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
