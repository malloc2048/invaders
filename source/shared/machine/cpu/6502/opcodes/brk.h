#ifndef NESEMU_BRK_H
#define NESEMU_BRK_H

#include "cpu/6502/opcode.h"

class BRK: public OpCode {
public:
    BRK() = delete;
    ~BRK() = default;
    BRK(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        opcode = 0x00;
        nemonic = "BRK";

        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute() override {
        return 1;
    }
};
#endif
