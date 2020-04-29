#ifndef NESEMU_ORAX_H
#define NESEMU_ORAX_H

#include "machine/cpu/8080/opcode.h"

class ORA_X: public OpCode {
public:
    ORA_X() = delete;
    ~ORA_X() = default;
    ORA_X(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        return 1;
    }

    void Disassemble(std::ostream& out) override {
    }
};
#endif
