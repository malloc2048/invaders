#ifndef NESEMU_DAD_H
#define NESEMU_DAD_H

#include "cpu/8080/opcode.h"

class DAD: public OpCode {
public:
    DAD() = default;
    ~DAD() = default;
    DAD(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint32_t sum;
        switch(rp) {
            case BC:
                sum = registers->hl.d16 + registers->bc.d16;
                break;
            case DE:
                sum = registers->hl.d16 + registers->de.d16;
                break;
            case HL:
                sum = registers->hl.d16 + registers->hl.d16;
                break;
            case SP:
                sum = registers->hl.d16 + registers->sp.d16;
                break;
            default:
                sum = registers->hl.d16;
                break;
        }
        registers->hl.d16 = sum & 0x0000ffffu;
        flags->carry = (sum & 0xffff0000u) > 0 ? 1 : 0;

        return 1;
    }

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tDAD " << registerPairNames[rp];
        registers->pc.d16 += 1;
    }
};
#endif
