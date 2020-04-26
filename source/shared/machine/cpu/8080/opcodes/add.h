#ifndef NESEMU_ADD_H
#define NESEMU_ADD_H

#include "cpu/8080/opcode.h"

class ADD: public OpCode {
public:
    ADD() = delete;
    ~ADD() = default;
    ADD(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t sum;
        switch(src) {
            case B:
                sum = registers->a + registers->bc.bytes.high;
                break;
            case C:
                sum = registers->a + registers->bc.bytes.low;
                break;
            case D:
                sum = registers->a + registers->de.bytes.high;
                break;
            case E:
                sum = registers->a + registers->de.bytes.low;
                break;
            case H:
                sum = registers->a + registers->hl.bytes.high;
                break;
            case L:
                sum = registers->a + registers->hl.bytes.low;
                break;
            case M:
                sum = registers->a + ram->read(registers->hl.d16);
                break;
            case A:
                sum = registers->a + registers->a;
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
            << (unsigned)ram->read(registers->pc.d16) << "\tADD " << OpCode::registerNames[src];
        registers->pc.d16 += 1;
    }
};

#endif
