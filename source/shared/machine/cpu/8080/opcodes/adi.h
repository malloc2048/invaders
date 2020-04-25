#ifndef NESEMU_ADI_H
#define NESEMU_ADI_H

#include "cpu/8080/opcode.h"

class ADI: public OpCode {
public:
    ADI() = delete;
    ~ADI() = default;
    ADI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t sum = registers->a + ram->read(registers->pc.d16 + 1);
        updateFlags(sum);
        updateAuxiliaryCarry(registers->a, sum);
        flags->carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers->a = sum & 0x00ffu;

        return 2;
    }
};

#endif
