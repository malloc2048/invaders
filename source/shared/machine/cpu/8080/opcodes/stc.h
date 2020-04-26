#ifndef NESEMU_STC_H
#define NESEMU_STC_H

#include "cpu/8080/opcode.h"

class STC: public OpCode {
public:
    STC() = delete;
    ~STC() = default;

    STC(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        flags->carry = 1;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tSTC";
        registers->pc.d16 += 1;
    }
};
#endif
