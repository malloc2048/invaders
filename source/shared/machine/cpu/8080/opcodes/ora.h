#ifndef NESEMU_ORA_H
#define NESEMU_ORA_H

#include "cpu/8080/opcode.h"

class ORA: public OpCode {
public:
    ORA() = delete;
    ~ORA() = default;
    ORA(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;

        uint16_t result;
        switch(src) {
            case B:
                result = registers->a | registers->bc.bytes.high;
                break;
            case C:
                result = registers->a | registers->bc.bytes.low;
                break;
            case D:
                result = registers->a | registers->de.bytes.high;
                break;
            case E:
                result = registers->a | registers->de.bytes.low;
                break;
            case H:
                result = registers->a | registers->hl.bytes.high;
                break;
            case L:
                result = registers->a | registers->hl.bytes.low;
                break;
            case M:
                result = registers->a | ram->read(registers->hl.d16);
                break;
            case A:
            default:
                result = registers->a;
                break;
        }
        updateFlags(result);
        flags->carry = 0;
        flags->auxiliary = 0;
        registers->a = result & 0x00ffu;

        return 1;
    }
};

#endif
