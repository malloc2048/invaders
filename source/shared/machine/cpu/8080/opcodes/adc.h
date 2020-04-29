#ifndef NESEMU_ADC_H
#define NESEMU_ADC_H

#include "cpu/8080/opcode.h"

class ADC: public OpCode {
public:
    ADC() = delete;
    ~ADC() = default;
    ADC(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint8_t src = opcode & 0x07u;

        uint16_t sum;
        switch(src) {
            case B:
                sum = registers->a + registers->bc.bytes.high + flags->carry;
                break;
            case C:
                sum = registers->a + registers->bc.bytes.low + flags->carry;
                break;
            case D:
                sum = registers->a + registers->de.bytes.high + flags->carry;
                break;
            case E:
                sum = registers->a + registers->de.bytes.low + flags->carry;
                break;
            case H:
                sum = registers->a + registers->hl.bytes.high + flags->carry;
                break;
            case L:
                sum = registers->a + registers->hl.bytes.low + flags->carry;
                break;
            case M:
                sum = registers->a + ram->read(registers->hl.d16) + flags->carry;
                break;
            case A:
                sum = registers->a + registers->a + flags->carry;
                break;
            default:
                sum = registers->a;
                break;
        }
        updateFlags(sum);
        updateAuxiliaryCarry(registers->a, sum);
        flags->carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers->a = sum & 0x00ffu;

        return 1;
    }

    void Disassemble(std::ostream& out) override {
        uint8_t src = ram->read(registers->pc.d16) & 0x07u;
        out << std::hex << std::setw(2) << std::setfill('0')
            << (unsigned)ram->read(registers->pc.d16) << "\tADC " << registerNames[src];
        registers->pc.d16 += 1;
    }
};

#endif
