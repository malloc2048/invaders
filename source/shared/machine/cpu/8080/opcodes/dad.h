#ifndef NESEMU_DAD_H
#define NESEMU_DAD_H

#include "cpu/8080/opcode.h"

class DAD: public OpCode {
public:
    DAD() = default;
    ~DAD() = default;
    DAD(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint32_t sum;
        switch(rp) {
            case BC:
                sum = registers->hl.d16 + registers->bc.d16;
                break;
            case DE:
                sum = registers->hl.d16 + registers->de.d16;
                break;
            case HL:
                sum = registers->hl.d16 + registers->hl.d16;
                break;
            case SP:
                sum = registers->hl.d16 + registers->sp.d16;
                break;
            default:
                sum = registers->hl.d16;
                break;
        }
        registers->hl.d16 = sum & 0x0000ffffu;
        flags->carry = (sum & 0xffff0000u) > 0 ? 1 : 0;

        return 1;
    }
};
#endif
