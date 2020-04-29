#ifndef NESEMU_XRA_H
#define NESEMU_XRA_H

#include "cpu/8080/opcode.h"

class XRA: public OpCode {
public:
    XRA() = delete;
    ~XRA() = default;
    XRA(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint8_t src = opcode & 0x07u;

        uint16_t result;
        switch(src) {
            case B:
                result = registers->a ^ registers->bc.bytes.high;
                break;
            case C:
                result = registers->a ^ registers->bc.bytes.low;
                break;
            case D:
                result = registers->a ^ registers->de.bytes.high;
                break;
            case E:
                result = registers->a ^ registers->de.bytes.low;
                break;
            case H:
                result = registers->a ^ registers->hl.bytes.high;
                break;
            case L:
                result = registers->a ^ registers->hl.bytes.low;
                break;
            case M:
                result = registers->a ^ ram->read(registers->hl.d16);
                break;
            case A:
            default:
                result = registers->a;
                break;
        }
        updateFlags(result);
        flags->carry = 0;
        flags->auxiliary = 0;
        registers->a = result & 0x00ffu;

        return 1;
    }

    void Disassemble(std::ostream& out) override {
        uint8_t src = ram->read(registers->pc.d16) & 0x07u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tXRA " << registerNames[src];
        registers->pc.d16 += 1;
    }
};
#endif
