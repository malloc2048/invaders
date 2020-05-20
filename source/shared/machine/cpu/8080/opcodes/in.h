#ifndef EMULATOR_IN_H
#define EMULATOR_IN_H

#include "machine/cpu/8080/opcode.h"

class IN: public OpCode {
public:
    IN() = delete;
    ~IN() = default;
    IN(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tIN " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};
#endif
