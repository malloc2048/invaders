#ifndef NESEMU_SPHL_H
#define NESEMU_SPHL_H

#include "cpu/8080/opcode.h"

class SPHL: public OpCode {
public:
    SPHL() = delete;
    ~SPHL() = default;
    SPHL(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        registers->sp.d16 = registers->hl.d16;
        return 1;
    }
};
#endif
