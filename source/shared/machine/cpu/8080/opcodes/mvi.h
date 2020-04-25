#ifndef NESEMU_MVI_H
#define NESEMU_MVI_H

#include "cpu/8080/opcode.h"

class MVI: public OpCode {
public:
    MVI() = delete;
    ~MVI() = default;

    MVI(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto r = (opcode & 0x38u) >> 3u;

        auto value = ram->read(registers->pc.d16 + 1);
        switch(r) {
            case B:
                registers->bc.bytes.high = value;
                break;
            case C:
                registers->bc.bytes.low = value;
                break;
            case D:
                registers->de.bytes.high = value;
                break;
            case E:
                registers->de.bytes.low = value;
                break;
            case H:
                registers->hl.bytes.high = value;
                break;
            case L:
                registers->hl.bytes.low = value;
                break;
            case M:
                ram->write(registers->hl.d16, value);
                break;
            case A:
                registers->a = value;
                break;
            default:
                break;
        }
        return 2;
    }
};
#endif
