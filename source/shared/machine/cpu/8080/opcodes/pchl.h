#ifndef EMULATOR_PCHL_H
#define EMULATOR_PCHL_H

#include "machine/cpu/8080/opcode.h"

class PCHL: public OpCode {
public:
    PCHL() = delete;
    ~PCHL() = default;
    PCHL(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
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
