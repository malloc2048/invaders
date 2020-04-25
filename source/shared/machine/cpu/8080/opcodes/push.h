#ifndef NESEMU_PUSH_H
#define NESEMU_PUSH_H

#include "cpu/8080/opcode.h"

class PUSH: public OpCode {
public:
    PUSH() = delete;
    ~PUSH() = default;

    PUSH(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint8_t value;
        switch(rp) {
            case BC:
                ram->write(registers->sp.d16 - 1, registers->bc.bytes.high);
                ram->write(registers->sp.d16 - 2, registers->bc.bytes.low);
                registers->sp.d16 -= 2;
                break;
            case DE:
                ram->write(registers->sp.d16 - 1, registers->de.bytes.high);
                ram->write(registers->sp.d16 - 2, registers->de.bytes.low);
                registers->sp.d16 -= 2;
                break;
            case HL:
                ram->write(registers->sp.d16 - 1, registers->hl.bytes.high);
                ram->write(registers->sp.d16 - 2, registers->hl.bytes.low);
                registers->sp.d16 -= 2;
                break;
            case SP: {// push the PSW
                ram->write(registers->sp.d16 - 1, registers->a);
                ram->write(registers->sp.d16 - 2, flags->d8);
                registers->sp.d16 -= 2;
                break;
            }
            default:
                break;
        }
        return 1;
    }
};
#endif
