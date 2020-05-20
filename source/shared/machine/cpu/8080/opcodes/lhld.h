#ifndef EMULATOR_LHLD_H
#define EMULATOR_LHLD_H

#include "machine/cpu/8080/opcode.h"

class LHLD: public OpCode {
public:
    LHLD() = delete;
    ~LHLD() = default;

    LHLD(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        RegisterPair address {};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->hl.bytes.low = ram->read(address.d16);

        address.d16 += 1;
        registers->hl.bytes.high = ram->read(address.d16);
        return 3;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tLHLD " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;


    }
};
#endif
