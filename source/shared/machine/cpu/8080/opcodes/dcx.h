#ifndef NESEMU_DCX_H
#define NESEMU_DCX_H

#include "cpu/8080/opcode.h"

class DCX: public OpCode {
public:
    DCX() = delete;
    ~DCX() = default;

    DCX(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint8_t value;
        switch(rp) {
            case BC:
                registers->bc.d16 -= 1;
                break;
            case DE:
                registers->de.d16 -= 1;
                break;
            case HL:
                registers->hl.d16 -= 1;
                break;
            case SP:
                registers->sp.d16 -= 1;
            default:
                break;
        }
        return 1;
    }
};
#endif
