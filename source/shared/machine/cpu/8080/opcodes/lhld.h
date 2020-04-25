#ifndef NESEMU_LHLD_H
#define NESEMU_LHLD_H

#include "cpu/8080/opcode.h"

class LHLD: public OpCode {
public:
    LHLD() = delete;
    ~LHLD() = default;

    LHLD(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        RegisterPair address {};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->hl.bytes.low = ram->read(address.d16);

        address.d16 += 1;
        registers->hl.bytes.high = ram->read(address.d16);
        return 3;
    }
};
#endif
