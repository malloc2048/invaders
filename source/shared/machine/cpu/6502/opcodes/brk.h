#ifndef NESEMU_BRK_H
#define NESEMU_BRK_H

#include "cpu/6502/opcode.h"

class BRK: public OpCode {
public:
    BRK() = delete;
    ~BRK() = default;
    BRK(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        opcode = 0x00;
        nemonic = "BRK";

        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute() override {
        return 1;
    }

    void Disassemble(std::ostream& out) override {

    }
};
#endif
