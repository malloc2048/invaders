#ifndef NESEMU_POP_H
#define NESEMU_POP_H

#include "cpu/8080/opcode.h"

class POP: public OpCode {
public:
    POP() = delete;
    ~POP() = default;

    POP(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint8_t value;
        switch(rp) {
            case BC:
                registers->bc.bytes.low = ram->read(registers->sp.d16);
                registers->bc.bytes.high = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            case DE:
                registers->de.bytes.low = ram->read(registers->sp.d16);
                registers->de.bytes.high = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            case HL:
                registers->hl.bytes.low = ram->read(registers->sp.d16);
                registers->hl.bytes.high = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            case SP: {// this restores the PSW
                flags->d8 = ram->read(registers->sp.d16);
                registers->a = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            }
            default:
                break;
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tPOP " << registerPairNames[rp];
        registers->pc.d16 += 1;
    }
};
#endif
