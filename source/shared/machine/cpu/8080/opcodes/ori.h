#ifndef NESEMU_ORI_H
#define NESEMU_ORI_H

#include "cpu/8080/opcode.h"

class ORI: public OpCode {
public:
    ORI() = delete;
    ~ORI() = default;
    ORI(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint16_t result = registers->a | ram->read(registers->pc.d16 + 1);
        updateFlags(result);
        flags->carry = 0;
        flags->auxiliary = 0;
        registers->a = result & 0x00ffu;

        return 2;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tORI " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};

#endif
