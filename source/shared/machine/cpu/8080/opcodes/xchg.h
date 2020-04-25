#ifndef NESEMU_XCHG_H
#define NESEMU_XCHG_H

#include "cpu/8080/opcode.h"

class XCHG: public OpCode {
public:
    XCHG() = delete;
    ~XCHG() = default;
    XCHG(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t tmp = registers->hl.d16;
        registers->hl.d16 = registers->de.d16;
        registers->de.d16 = tmp;

        return 1;
    }
};
#endif
