#ifndef INVADERS_SBB_H
#define INVADERS_SBB_H

#include "opcode.h"

class SBB: public Instruction {
public:
    SBB() = delete;
    ~SBB() = default;
    SBB(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t diff;
        switch(src) {
            case B:
                diff = registers.a - registers.bc.bytes.high - flags.carry;
                break;
            case C:
                diff = registers.a - registers.bc.bytes.low - flags.carry;
                break;
            case D:
                diff = registers.a - registers.de.bytes.high - flags.carry;
                break;
            case E:
                diff = registers.a - registers.de.bytes.low - flags.carry;
                break;
            case H:
                diff = registers.a - registers.hl.bytes.high - flags.carry;
                break;
            case L:
                diff = registers.a - registers.hl.bytes.low - flags.carry;
                break;
            case M:
                diff = registers.a - memory.read_byte(registers.hl.d16) - flags.carry;
                break;
            case A:
                diff = registers.a - registers.a - flags.carry;
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
