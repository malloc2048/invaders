#ifndef EMULATOR_EI_H
#define EMULATOR_EI_H

#include "machine/cpu/8080/opcode.h"

class EI: public OpCode {
public:
    EI() = delete;
    ~EI() = default;
    EI(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        registers->intEnabled = 1;
        registers->interruptDelay = 1;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tEI";
        registers->pc.d16 += 1;


    }
};
#endif
