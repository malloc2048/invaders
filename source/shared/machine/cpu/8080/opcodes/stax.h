#ifndef NESEMU_STAX_H
#define NESEMU_STAX_H

#include "cpu/8080/opcode.h"

class STAX: public OpCode {
public:
    STAX() = delete;
    ~STAX() = default;

    STAX(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        switch(rp) {
            case BC:
                registers->a = ram->read(registers->bc.d16);
                break;
            case DE:
                registers->a = ram->read(registers->de.d16);
                break;
            default:
                break;
        }
        return 1;
    }
};
#endif
