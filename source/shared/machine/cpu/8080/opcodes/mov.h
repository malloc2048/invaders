#ifndef NESEMU_MOV_H
#define NESEMU_MOV_H

#include "cpu/8080/opcode.h"

class MOV: public OpCode {
public:
    MOV() = delete;
    ~MOV() = default;
    MOV(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;
        uint8_t dst = opcode & 0x3fu;

        switch(src) {
            case B:
                move(dst, registers->bc.bytes.high);
                break;
            case C:
                move(dst, registers->bc.bytes.low);
                break;
            case D:
                move(dst, registers->de.bytes.high);
                break;
            case E:
                move(dst, registers->de.bytes.low);
                break;
            case H:
                move(dst, registers->hl.bytes.high);
                break;
            case L:
                move(dst, registers->hl.bytes.low);
                break;
            case M:
                move(dst, ram->read(registers->hl.d16));
                break;
            case A:
                move(dst, registers->a);
                break;
            default:
                break;
        }

        return 1;
    }

    void move(uint8_t dst, uint8_t value) {
        switch(dst) {
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
    }
};

#endif
