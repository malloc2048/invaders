#ifndef NESEMU_PCHL_H
#define NESEMU_PCHL_H

#include "cpu/8080/opcode.h"

class PCHL: public OpCode {
public:
    PCHL() = delete;
    ~PCHL() = default;
    PCHL(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        registers->pc.d16 = registers->hl.d16;
        return 0;
    }
};

#endif
