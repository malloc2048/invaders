#ifndef NESEMU_ROTATE_H
#define NESEMU_ROTATE_H

#include "cpu/8080/opcode.h"

class Rotate: public OpCode {
public:
    Rotate() = delete;
    ~Rotate() = default;

    Rotate(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        switch(opcode) {
            case 0x07:  // RLC
                flags->carry = (registers->a & 0x80u) > 0 ? 1 : 0;
                registers->a = (unsigned)registers->a << 0x01u & flags->carry;
                break;
            case 0x0f:  // RRC
                flags->carry = (registers->a & 0x01u);
                registers->a = (unsigned)registers->a >> 0x01u;
                registers->a &= flags->carry == 0 ? 0x7fu : 0xffu;
                break;
            case 0x17: { // RAL
                auto bit7 = (registers->a & 0x80u) > 0 ? 1 : 0;
                registers->a = (unsigned) registers->a << 0x01u & flags->carry;
                flags->carry = bit7 > 0 ? 1 : 0;
                break;
            }
            case 0x1f: { // RAR
                auto bit0 = registers->a & 0x01u;
                registers->a = (unsigned) registers->a >> 0x01u;
                registers->a &= flags->carry == 0 ? 0x7fu : 0xffu;
                flags->carry = bit0;
                break;
            }
            default:
                break;
        }
        return 1;
    }
};

#endif
