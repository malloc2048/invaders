#ifndef NESEMU_XTHL_H
#define NESEMU_XTHL_H

#include "cpu/8080/opcode.h"

class XTHL: public OpCode {
public:
    XTHL() = delete;
    ~XTHL() = default;
    XTHL(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        RegisterPair tmp = registers->hl;
        registers->hl.bytes.low = ram->read(registers->sp.d16);
        registers->hl.bytes.low = ram->read(registers->sp.d16 + 1);

        ram->write(registers->sp.d16, tmp.bytes.low);
        ram->write(registers->sp.d16 + 1, tmp.bytes.high);

        return 1;
    }
};
#endif
