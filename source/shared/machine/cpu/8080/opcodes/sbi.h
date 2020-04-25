#ifndef NESEMU_SBI_H
#define NESEMU_SBI_H

#include "cpu/8080/opcode.h"

class SBI: public OpCode {
public:
    SBI() = delete;
    ~SBI() = default;
    SBI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t result = registers->a - ram->read(registers->pc.d16 + 1) - flags->carry;

        updateFlags(result);
        updateAuxiliaryCarry(registers->a, result);
        flags->carry = (result & 0xff00u) > 0 ? 1 : 0;
        registers->a = result & 0x00ffu;

        return 2;
    }
};
#endif
