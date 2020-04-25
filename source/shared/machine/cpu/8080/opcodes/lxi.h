#ifndef NESEMU_LXI_H
#define NESEMU_LXI_H

#include "cpu/8080/opcode.h"

class LXI: public OpCode {
public:
    LXI() = delete;
    ~LXI() = default;

    LXI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        switch(rp) {
            case BC:
                registers->bc.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->bc.bytes.high = ram->read(registers->pc.d16 + 2);
                break;
            case DE:
                registers->de.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->de.bytes.high = ram->read(registers->pc.d16 + 2);
                break;
            case HL:
                registers->hl.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->hl.bytes.high = ram->read(registers->pc.d16 + 2);
                break;
            case SP:
                registers->sp.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->sp.bytes.high = ram->read(registers->pc.d16 + 2);
                break;
            default:
                break;
        }
        return 3;
    }
};
#endif
