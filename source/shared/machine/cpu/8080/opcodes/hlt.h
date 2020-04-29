#ifndef NESEMU_HLT_H
#define NESEMU_HLT_H

#include "cpu/8080/opcode.h"

class HLT: public OpCode {
public:
    HLT() = delete;
    ~HLT() = default;

    HLT(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        exit(0);
    }

    void Disassemble(std::ostream& out) override {
        out << "HLT";
        registers->pc.d16 += 1;
    }
};
#endif
