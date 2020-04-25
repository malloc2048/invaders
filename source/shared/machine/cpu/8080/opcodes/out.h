#ifndef NESEMU_OUT_H
#define NESEMU_OUT_H

#include "cpu/8080/opcode.h"

class OUT: public OpCode {
public:
    OUT() = delete;
    ~OUT() = default;
    OUT(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        return 1;
    }
};
#endif
