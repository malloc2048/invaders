#ifndef NESEMU_STC_H
#define NESEMU_STC_H

#include "cpu/8080/opcode.h"

class STC: public OpCode {
public:
    STC() = delete;
    ~STC() = default;

    STC(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        flags->carry = 1;
        return 1;
    }
};
#endif
