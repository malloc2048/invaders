#ifndef NESEMU_SUI_H
#define NESEMU_SUI_H

#include "cpu/8080/opcode.h"

class SUI: public OpCode {
public:
    SUI() = delete;
    ~SUI() = default;
    SUI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t result = registers->a - ram->read(registers->pc.d16 + 1);

        updateFlags(result);
        updateAuxiliaryCarry(registers->a, result);
        flags->carry = (result & 0xff00u) > 0 ? 1 : 0;
        registers->a = result & 0x00ffu;

        return 2;
    }
};

#endif
