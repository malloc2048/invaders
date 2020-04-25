#ifndef NESEMU_HLT_H
#define NESEMU_HLT_H

#include "cpu/8080/opcode.h"

class HLT: public OpCode {
public:
    HLT() = delete;
    ~HLT() = default;

    HLT(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        exit(0);
    }
};
#endif
