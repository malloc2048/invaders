#ifndef NESEMU_SBB_H
#define NESEMU_SBB_H

#include "cpu/8080/opcode.h"

class SBB: public OpCode {
public:
    SBB() = delete;
    ~SBB() = default;
    SBB(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t sum;
        switch(src) {
            case B:
                sum = registers->a - registers->bc.bytes.high - flags->carry;
                break;
            case C:
                sum = registers->a - registers->bc.bytes.low - flags->carry;
                break;
            case D:
                sum = registers->a - registers->de.bytes.high - flags->carry;
                break;
            case E:
                sum = registers->a - registers->de.bytes.low - flags->carry;
                break;
            case H:
                sum = registers->a - registers->hl.bytes.high - flags->carry;
                break;
            case L:
                sum = registers->a - registers->hl.bytes.low - flags->carry;
                break;
            case M:
                sum = registers->a - ram->read(registers->hl.d16) - flags->carry;
                break;
            case A:
                sum = registers->a - registers->a - flags->carry;
                break;
            default:
                sum = registers->a;
                break;
        }
        updateFlags(sum);
        updateAuxiliaryCarry(registers->a, sum);
        flags->carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers->a = sum & 0x00ffu;

        return 1;
    }
};

#endif
