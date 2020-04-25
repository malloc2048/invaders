#ifndef NESEMU_LDA_H
#define NESEMU_LDA_H

#include "cpu/8080/opcode.h"

class LDA: public OpCode {
public:
    LDA() = delete;
    ~LDA() = default;

    LDA(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        RegisterPair address {};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->a = ram->read(address.d16);
        return 3;
    }
};
#endif
