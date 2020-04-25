#ifndef NESEMU_DAA_H
#define NESEMU_DAA_H

#include "cpu/8080/opcode.h"

class DAA: public OpCode {
public:
    DAA() = default;
    ~DAA() = default;
    DAA(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        union Byte{
            struct {
                uint8_t low:4;
                uint8_t high:4;
            } bits;
            uint8_t d8;
        };

        Byte byte {};
        byte.d8 = registers->a;

        if(byte.bits.low > 9)
            byte.bits.low += 6;
        if(byte.bits.high > 9)
            byte.bits.high += 6;

        updateFlags(registers->a);
        updateAuxiliaryCarry(registers->a, byte.d8);
        flags->carry = byte.d8 < registers->a ? 1 : 0;
        return 1;
    }
};
#endif
