#ifndef NESEMU_STAX_H
#define NESEMU_STAX_H

#include "cpu/8080/opcode.h"

class STAX: public OpCode {
public:
    STAX() = delete;
    ~STAX() = default;

    STAX(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        auto rp = (opcode & 0x30u) >> 4u;

        switch(rp) {
            case BC:
                ram->write(registers->bc.d16, registers->a);
                break;
            case DE:
                ram->write(registers->de.d16, registers->a);
                break;
            default:
                break;
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tSTAX " << registerPairNames[rp];
        registers->pc.d16 += 1;
    }
};
#endif
