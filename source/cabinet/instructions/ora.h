#ifndef INVADERS_ORA_H
#define INVADERS_ORA_H

#include "instruction.h"

class ORA: public Instruction {
public:
    ORA() = delete;
    ~ORA() = default;
    ORA(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t result;
        switch(src) {
            case B:
                result = registers.a | registers.bc.bytes.high;
                break;
            case C:
                result = registers.a | registers.bc.bytes.low;
                break;
            case D:
                result = registers.a | registers.de.bytes.high;
                break;
            case E:
                result = registers.a | registers.de.bytes.low;
                break;
            case H:
                result = registers.a | registers.hl.bytes.high;
                break;
            case L:
                result = registers.a | registers.hl.bytes.low;
                break;
            case M:
                result = registers.a | memory.read_byte(registers.hl.d16);
                break;
            case A:
            default:
                result = registers.a;
                break;
        }
        updateFlags(result);
        flags.carry = 0;
        flags.halfCarry = 0;
        registers.a = result & 0x00ffu;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};

#endif
