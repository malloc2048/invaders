#ifndef INVADERS_SUB_H
#define INVADERS_SUB_H

#include "opcode.h"

class SUB: public OpCode {
public:
    SUB() = delete;
    ~SUB() = default;
    SUB(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t diff;
        switch(src) {
            case B:
                diff = registers.a - registers.bc.bytes.high;
                break;
            case C:
                diff = registers.a - registers.bc.bytes.low;
                break;
            case D:
                diff = registers.a - registers.de.bytes.high;
                break;
            case E:
                diff = registers.a - registers.de.bytes.low;
                break;
            case H:
                diff = registers.a - registers.hl.bytes.high;
                break;
            case L:
                diff = registers.a - registers.hl.bytes.low;
                break;
            case M:
                diff = registers.a - memory.readByte(registers.hl.d16);
                break;
            case A:
                diff = registers.a - registers.a;
                break;
            default:
                diff = registers.a;
                break;
        }
        flags.halfCarry = (diff & 0x000fu) > (registers.a & 0x0fu) ? 1 : 0;
        updateFlags(diff);
        flags.carry = (diff & 0x100u) != 0 ? 1 : 0;

        registers.a = diff & 0x00ffu;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};

#endif
