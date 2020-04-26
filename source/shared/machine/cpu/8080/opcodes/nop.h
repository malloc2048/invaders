#ifndef NESEMU_NOP_H
#define NESEMU_NOP_H

#include "cpu/8080/opcode.h"

class NOP: public OpCode {
public:
    NOP() = delete;
    ~NOP() = default;
    NOP(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tNOP";
        registers->pc.d16 += 1;
    }
};
#endif
