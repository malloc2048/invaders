#ifndef EMULATOR_OUT_H
#define EMULATOR_OUT_H

#include "machine/cpu/8080/opcode.h"

class OUT: public OpCode {
public:
    OUT() = delete;
    ~OUT() = default;
    OUT(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        return 2;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tOUT " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};
#endif
