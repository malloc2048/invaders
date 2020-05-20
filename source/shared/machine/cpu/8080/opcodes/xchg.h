#ifndef EMULATOR_XCHG_H
#define EMULATOR_XCHG_H

#include "machine/cpu/8080/opcode.h"

class XCHG: public OpCode {
public:
    XCHG() = delete;
    ~XCHG() = default;
    XCHG(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint16_t tmp = registers->hl.d16;
        registers->hl.d16 = registers->de.d16;
        registers->de.d16 = tmp;

        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tXCHG";
        registers->pc.d16 += 1;


    }
};
#endif
