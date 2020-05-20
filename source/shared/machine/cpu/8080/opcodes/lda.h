#ifndef EMULATOR_LDA_H
#define EMULATOR_LDA_H

#include "machine/cpu/8080/opcode.h"

class LDA: public OpCode {
public:
    LDA() = delete;
    ~LDA() = default;

    LDA(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        RegisterPair address {};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->a = ram->read(address.d16);
        return 3;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tLDA "
           << (unsigned)ram->read(registers->pc.d16 + 2) <<  (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;
    }
};
#endif
