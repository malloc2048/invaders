#ifndef NESEMU_XRI_H
#define NESEMU_XRI_H

#include "cpu/8080/opcode.h"

class XRI: public OpCode {
public:
    XRI() = delete;
    ~XRI() = default;
    XRI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint16_t result = registers->a ^ ram->read(registers->pc.d16 + 1);
        updateFlags(result);
        flags->carry = 0;
        flags->auxiliary = 0;
        registers->a = result & 0x00ffu;

        return 2;
    }
};

#endif
