#ifndef NESEMU_SUI_H
#define NESEMU_SUI_H

#include "cpu/8080/opcode.h"

class SUI: public OpCode {
public:
    SUI() = delete;
    ~SUI() = default;
    SUI(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t result = registers->a - ram->read(registers->pc.d16 + 1);

        updateFlags(result);
        updateAuxiliaryCarry(registers->a, result);
        flags->carry = (result & 0xff00u) > 0 ? 1 : 0;
        registers->a = result & 0x00ffu;

        return 2;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tSUI " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};

#endif
