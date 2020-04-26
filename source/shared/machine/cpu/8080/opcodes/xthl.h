#ifndef NESEMU_XTHL_H
#define NESEMU_XTHL_H

#include "cpu/8080/opcode.h"

class XTHL: public OpCode {
public:
    XTHL() = delete;
    ~XTHL() = default;
    XTHL(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        RegisterPair tmp = registers->hl;
        registers->hl.bytes.low = ram->read(registers->sp.d16);
        registers->hl.bytes.low = ram->read(registers->sp.d16 + 1);

        ram->write(registers->sp.d16, tmp.bytes.low);
        ram->write(registers->sp.d16 + 1, tmp.bytes.high);

        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tXTHL";
        registers->pc.d16 += 1;


    }
};
#endif
