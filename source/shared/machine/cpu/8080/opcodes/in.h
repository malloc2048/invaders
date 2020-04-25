#ifndef NESEMU_IN_H
#define NESEMU_IN_H

#include "cpu/8080/opcode.h"

class IN: public OpCode {
public:
    IN() = delete;
    ~IN() = default;
    IN(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        return 1;
    }
};
#endif
