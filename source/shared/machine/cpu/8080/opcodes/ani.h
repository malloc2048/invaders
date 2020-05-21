#ifndef EMULATOR_ANI_H
#define EMULATOR_ANI_H

#include "machine/cpu/8080/opcode.h"

class ANI: public OpCode {
public:
    ANI() = delete;
    ~ANI() = default;
    ANI(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint16_t result = registers->a & ram->read(registers->pc.d16 + 1);

        updateFlags(result);
        updateCarry(registers->a, result);
        flags->carry = 0;
        registers->a = result & 0x00ffu;

        return 2;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16) << "\tANI "
            << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};

#endif
