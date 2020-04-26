#ifndef NESEMU_ACI_H
#define NESEMU_ACI_H

#include "cpu/8080/opcode.h"

class ACI: public OpCode {
public:
    ACI() = delete;
    ~ACI() = default;
    ACI(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t sum = registers->a + ram->read(registers->pc.d16 + 1) + flags->carry;
        updateFlags(sum);
        updateAuxiliaryCarry(registers->a, sum);
        flags->carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers->a = sum & 0x00ffu;

        return 2;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0') << "ACI " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};
#endif
