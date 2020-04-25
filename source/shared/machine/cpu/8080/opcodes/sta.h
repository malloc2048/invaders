#ifndef NESEMU_STA_H
#define NESEMU_STA_H

#include "cpu/8080/opcode.h"

class STA: public OpCode {
public:
    STA() = delete;
    ~STA() = default;

    STA(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        RegisterPair address {};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        ram->write(address.d16, registers->a);
        return 3;
    }
};
#endif
