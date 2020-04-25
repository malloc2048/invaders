#ifndef NESEMU_SHLD_H
#define NESEMU_SHLD_H

#include "cpu/8080/opcode.h"

class SHLD: public OpCode {
public:
    SHLD() = delete;
    ~SHLD() = default;
    SHLD(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        RegisterPair address {};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        ram->write(address.d16, registers->hl.bytes.low);

        address.d16 += 1;
        ram->write(address.d16, registers->hl.bytes.high);
        return 3;
    }
};
#endif
