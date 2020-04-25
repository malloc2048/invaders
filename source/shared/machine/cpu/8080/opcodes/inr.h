#ifndef NESEMU_INR_H
#define NESEMU_INR_H

#include "cpu/8080/opcode.h"

class INR: public OpCode {
public:
    INR() = delete;
    ~INR() = default;

    INR(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        auto r = (opcode & 0x38u) >> 3u;

        uint8_t value;
        switch(r) {
            case B:
                value = registers->bc.bytes.high + 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->bc.bytes.high, value);
                registers->bc.bytes.high = value;
                break;
            case C:
                value = registers->bc.bytes.low + 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->bc.bytes.low, value);
                registers->bc.bytes.high = value;
                break;
            case D:
                value = registers->de.bytes.high + 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->de.bytes.high, value);
                registers->de.bytes.high = value;
                break;
            case E:
                value = registers->de.bytes.low + 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->de.bytes.low, value);
                registers->de.bytes.high = value;
                break;
            case H:
                value = registers->hl.bytes.high + 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->hl.bytes.high, value);
                registers->hl.bytes.high = value;
                break;
            case L:
                value = registers->hl.bytes.low + 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->hl.bytes.low, value);
                registers->hl.bytes.high = value;
                break;
            case M:
                value = ram->read(registers->hl.d16) + 1;
                updateFlags(value);
                updateAuxiliaryCarry(ram->read(registers->hl.d16), value);
                ram->write(registers->hl.d16, value);
                break;
            case A:
                value = registers->a + 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->a, value);
                registers->a = value;
                break;
            default:
                break;
        }
        return 1;
    }
};
#endif
