#ifndef NESEMU_CMC_H
#define NESEMU_CMC_H

#include "cpu/8080/opcode.h"

class CMC: public OpCode {
public:
    CMC() = delete;
    ~CMC() = default;
    CMC(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        flags->carry = !flags->carry;
        return 1;
    }
};
#endif
