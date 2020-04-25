#ifndef NESEMU_EI_H
#define NESEMU_EI_H

#include "cpu/8080/opcode.h"

class EI: public OpCode {
public:
    EI() = delete;
    ~EI() = default;
    EI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        registers->intEnabled = 1;
        return 1;
    }
};
#endif
