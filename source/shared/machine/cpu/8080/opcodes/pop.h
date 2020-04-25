#ifndef NESEMU_POP_H
#define NESEMU_POP_H

#include "cpu/8080/opcode.h"

class POP: public OpCode {
public:
    POP() = delete;
    ~POP() = default;

    POP(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint8_t value;
        switch(rp) {
            case BC:
                registers->bc.bytes.low = ram->read(registers->sp.d16);
                registers->bc.bytes.high = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            case DE:
                registers->de.bytes.low = ram->read(registers->sp.d16);
                registers->de.bytes.high = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            case HL:
                registers->hl.bytes.low = ram->read(registers->sp.d16);
                registers->hl.bytes.high = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            case SP: {// this restores the PSW
                flags->d8 = ram->read(registers->sp.d16);
                registers->a = ram->read(registers->sp.d16 + 1);
                registers->sp.d16 += 2;
                break;
            }
            default:
                break;
        }
        return 1;
    }
};
#endif
