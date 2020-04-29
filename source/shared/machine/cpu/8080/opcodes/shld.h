#ifndef NESEMU_SHLD_H
#define NESEMU_SHLD_H

#include "cpu/8080/opcode.h"

class SHLD: public OpCode {
public:
    SHLD() = delete;
    ~SHLD() = default;
    SHLD(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        RegisterPair address {};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        ram->write(address.d16, registers->hl.bytes.low);

        address.d16 += 1;
        ram->write(address.d16, registers->hl.bytes.high);
        return 3;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16)
            << "\tSHLD " << (unsigned)ram->read(registers->pc.d16 + 2) <<  (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;


    }
};
#endif
