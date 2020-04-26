#ifndef NESEMU_CMC_H
#define NESEMU_CMC_H

#include "cpu/8080/opcode.h"

class CMC: public OpCode {
public:
    CMC() = delete;
    ~CMC() = default;
    CMC(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        flags->carry = !flags->carry;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << (unsigned)ram->read(registers->pc.d16) << "\tCMC";
        registers->pc.d16 += 1;


    }
};
#endif
