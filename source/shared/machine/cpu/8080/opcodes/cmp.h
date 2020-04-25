#ifndef NESEMU_CMP_H
#define NESEMU_CMP_H

#include "cpu/8080/opcode.h"

class CMP: public OpCode {
public:
    CMP() = delete;
    ~CMP() = default;
    CMP(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t result;
        switch(src) {
            case B:
                result = registers->a - registers->bc.bytes.high;
                break;
            case C:
                result = registers->a - registers->bc.bytes.low;
                break;
            case D:
                result = registers->a - registers->de.bytes.high;
                break;
            case E:
                result = registers->a - registers->de.bytes.low;
                break;
            case H:
                result = registers->a - registers->hl.bytes.high;
                break;
            case L:
                result = registers->a - registers->hl.bytes.low;
                break;
            case M:
                result = registers->a - ram->read(registers->hl.d16);
                break;
            case A:
                result = registers->a - registers->a;
                break;
            default:
                result = registers->a;
                break;
        }
        updateFlags(result);
        updateAuxiliaryCarry(registers->a, result);
        flags->carry = result < 0 ? 1 : 0;
        registers->a = result & 0x00ffu;

        return 1;
    }
};
#endif
