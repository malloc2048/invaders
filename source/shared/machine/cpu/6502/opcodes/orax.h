#ifndef NESEMU_ORAX_H
#define NESEMU_ORAX_H

#include "cpu/6502/opcode.h"

class ORA_X: public OpCode {
public:
    ORA_X() = delete;
    ~ORA_X() = default;
    ORA_X(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        opcode = 0x00;
        nemonic = "ORA X";

        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute() override {
        return 2;
    }
};
#endif
