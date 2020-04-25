#ifndef NESEMU_DI_H
#define NESEMU_DI_H

#include "cpu/8080/opcode.h"

class DI: public OpCode {
public:
    DI() = delete;
    ~DI() = default;
    DI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        registers->intEnabled = 0;
        return 1;
    }
};
#endif
