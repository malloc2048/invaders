#ifndef EMULATOR_HLT_H
#define EMULATOR_HLT_H

#include "machine/cpu/8080/opcode.h"

class HLT: public OpCode {
public:
    HLT() = delete;
    ~HLT() = default;

    HLT(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        registers->halted = true;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << "HLT";
        registers->pc.d16 += 1;
    }
};
#endif
