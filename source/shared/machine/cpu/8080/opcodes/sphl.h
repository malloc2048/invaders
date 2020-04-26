#ifndef NESEMU_SPHL_H
#define NESEMU_SPHL_H

#include "cpu/8080/opcode.h"

class SPHL: public OpCode {
public:
    SPHL() = delete;
    ~SPHL() = default;
    SPHL(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        registers->sp.d16 = registers->hl.d16;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << "" << (unsigned)ram->read(registers->pc.d16)
            << "\tSPHL";
        registers->pc.d16 += 1;


    }
};
#endif
