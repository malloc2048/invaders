#ifndef INVADERS_ADC_H
#define INVADERS_ADC_H

#include "instruction.h"

class ADC: public Instruction {
public:
    ADC() = delete;
    ~ADC() = default;
    ADC(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t sum;
        switch(src) {
            case B:
                sum = registers.a + registers.bc.bytes.high + flags.carry;
                break;
            case C:
                sum = registers.a + registers.bc.bytes.low + flags.carry;
                break;
            case D:
                sum = registers.a + registers.de.bytes.high + flags.carry;
                break;
            case E:
                sum = registers.a + registers.de.bytes.low + flags.carry;
                break;
            case H:
                sum = registers.a + registers.hl.bytes.high + flags.carry;
                break;
            case L:
                sum = registers.a + registers.hl.bytes.low + flags.carry;
                break;
            case M:
                sum = registers.a + memory.read_byte(registers.hl.d16) + flags.carry;
                break;
            case A:
                sum = registers.a + registers.a + flags.carry;
                break;
            default:
                registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
                return;
        }
        // use the original a value to calculate half carry
        flags.halfCarry = (registers.a & 0x0fu) > (sum & 0x000fu) ? 1 : 0;

        registers.a = sum & 0x00ffu;
        updateFlags(sum);
        flags.carry = (sum & 0x100u) != 0 ? 1 : 0;
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
