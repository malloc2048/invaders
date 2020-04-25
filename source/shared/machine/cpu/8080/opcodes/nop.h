#ifndef NESEMU_NOP_H
#define NESEMU_NOP_H

#include "cpu/8080/opcode.h"

class NOP: public OpCode {
public:
    NOP() = delete;
    ~NOP() = default;
    NOP(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        return 1;
    }
};
#endif
