#ifndef INVADERS_CMP_H
#define INVADERS_CMP_H

#include "opcode.h"

class CMP: public OpCode {
public:
    CMP() = delete;
    ~CMP() = default;
    CMP(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        switch(src) {
            case B:
                doCompare(registers.bc.bytes.high, opcode);
                break;
            case C:
                doCompare(registers.bc.bytes.low, opcode);
                break;
            case D:
                doCompare(registers.de.bytes.high, opcode);
                break;
            case E:
                doCompare(registers.de.bytes.low, opcode);
                break;
            case H:
                doCompare(registers.hl.bytes.high, opcode);
                break;
            case L:
                doCompare(registers.hl.bytes.low, opcode);
                break;
            case M:
                doCompare(memory.read_byte(registers.hl.d16), opcode);
                break;
            case A:
                doCompare(registers.a, opcode);
                break;
            default:
                break;
        }
    }

    void doCompare(uint8_t value, uint8_t opcode) {
        uint16_t result = registers.a - value;

        updateFlags(result);
        flags.halfCarry = (result & 0x000fu) > (registers.a & 0x0fu) ? 1 : 0;
        flags.carry = (result & 0x0100u) != 0 ? 1 : 0;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
