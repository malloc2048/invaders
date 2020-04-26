#ifndef NESEMU_PCHL_H
#define NESEMU_PCHL_H

#include "cpu/8080/opcode.h"

class PCHL: public OpCode {
public:
    PCHL() = delete;
    ~PCHL() = default;
    PCHL(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        registers->pc.d16 = registers->hl.d16;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tPCHL";
        registers->pc.d16 += 1;


    }
};

#endif
