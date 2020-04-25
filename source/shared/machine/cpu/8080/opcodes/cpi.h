#ifndef NESEMU_CPI_H
#define NESEMU_CPI_H

#include "cpu/8080/opcode.h"

class CPI: public OpCode {
public:
    CPI() = delete;
    ~CPI() = default;
    CPI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t result = registers->a - ram->read(registers->pc.d16 + 1);
        updateFlags(result);
        updateAuxiliaryCarry(registers->a, result);
        flags->carry = registers->a < ram->read(registers->pc.d16 + 1) ? 1 : 0;
        registers->a = result & 0x00ffu;

        return 2;
    }
};

#endif
