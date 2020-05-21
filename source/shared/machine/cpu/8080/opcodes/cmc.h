#ifndef EMULATOR_CMC_H
#define EMULATOR_CMC_H

#include "machine/cpu/8080/opcode.h"

class CMC: public OpCode {
public:
    CMC() = delete;
    ~CMC() = default;
    CMC(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        flags->carry = !flags->carry;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << (unsigned)ram->read(registers->pc.d16) << "\tCMC";
        registers->pc.d16 += 1;
    }
};
#endif
