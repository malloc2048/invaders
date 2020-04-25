#ifndef NESEMU_ACI_H
#define NESEMU_ACI_H

#include "cpu/8080/opcode.h"

class ACI: public OpCode {
public:
    ACI() = delete;
    ~ACI() = default;
    ACI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t sum = registers->a + ram->read(registers->pc.d16 + 1) + flags->carry;
        updateFlags(sum);
        updateAuxiliaryCarry(registers->a, sum);
        flags->carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers->a = sum & 0x00ffu;

        return 2;
    }
};

#endif
