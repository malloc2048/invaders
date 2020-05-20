#ifndef EMULATOR_ACI_H
#define EMULATOR_ACI_H

#include "machine/cpu/8080/opcode.h"

class ACI: public OpCode {
public:
    ACI() = delete;
    ~ACI() = default;
    ACI(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint16_t sum = registers->a + ram->read(registers->pc.d16 + 1) + flags->carry;
        updateFlags(sum);
        updateCarry(registers->a, sum);
        flags->carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers->a = sum & 0x00ffu;

        return 2;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << (unsigned)ram->read(registers->pc.d16) << std::hex << std::setw(2) << std::setfill('0') << "\tACI " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};
#endif
