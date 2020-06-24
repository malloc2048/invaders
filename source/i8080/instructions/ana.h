#ifndef INVADERS_ANA_H
#define INVADERS_ANA_H

#include "opcode.h"

class ANA: public Instruction {
public:
    ANA() = delete;
    ~ANA() = default;
    ANA(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        switch (src) {
            case B:
                doAnd(registers.bc.bytes.high, opcode);
                break;
            case C:
                doAnd(registers.bc.bytes.low, opcode);
                break;
            case D:
                doAnd(registers.de.bytes.high, opcode);
                break;
            case E:
                doAnd(registers.de.bytes.low, opcode);
                break;
            case H:
                doAnd(registers.hl.bytes.high, opcode);
                break;
            case L:
                doAnd(registers.hl.bytes.low, opcode);
                break;
            case M:
                doAnd(memory.read_byte(registers.hl.d16), opcode);
                break;
            case A:
                doAnd(registers.a, opcode);
                break;
            default:
                break;
        }
    }

    void doAnd(uint8_t value, uint8_t opcode) {
        uint8_t result = registers.a & value;

        updateFlags(result);
        flags.carry = 0;
        flags.halfCarry = ((registers.a | value) & 0x08u) != 0;
        registers.a = result;

        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
