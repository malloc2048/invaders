#ifndef NESEMU_DI_H
#define NESEMU_DI_H

#include "cpu/8080/opcode.h"

class DI: public OpCode {
public:
    DI() = delete;
    ~DI() = default;
    DI(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        registers->intEnabled = 0;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tDI";
        registers->pc.d16 += 1;
    }
};
#endif
