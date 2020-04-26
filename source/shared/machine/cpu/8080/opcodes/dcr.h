#ifndef NESEMU_DCR_H
#define NESEMU_DCR_H

#include "cpu/8080/opcode.h"

class DCR: public OpCode {
public:
    DCR() = delete;
    ~DCR() = default;

    DCR(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        auto r = (opcode & 0x38u) >> 3u;

        uint8_t value;
        switch(r) {
            case B:
                value = registers->bc.bytes.high - 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->bc.bytes.high, value);
                registers->bc.bytes.high = value;
                break;
            case C:
                value = registers->bc.bytes.low - 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->bc.bytes.low, value);
                registers->bc.bytes.high = value;
                break;
            case D:
                value = registers->de.bytes.high - 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->de.bytes.high, value);
                registers->de.bytes.high = value;
                break;
            case E:
                value = registers->de.bytes.low - 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->de.bytes.low, value);
                registers->de.bytes.high = value;
                break;
            case H:
                value = registers->hl.bytes.high - 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->hl.bytes.high, value);
                registers->hl.bytes.high = value;
                break;
            case L:
                value = registers->hl.bytes.low - 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->hl.bytes.low, value);
                registers->hl.bytes.high = value;
                break;
            case M:
                value = ram->read(registers->hl.d16) - 1;
                updateFlags(value);
                updateAuxiliaryCarry(ram->read(registers->hl.d16), value);
                ram->write(registers->hl.d16, value);
                break;
            case A:
                value = registers->a - 1;
                updateFlags(value);
                updateAuxiliaryCarry(registers->a, value);
                registers->a = value;
                break;
            default:
                break;
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        auto r = (ram->read(registers->pc.d16) & 0x38u) >> 3u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tDCR " << registerNames[r];
        registers->pc.d16 += 1;
    }
};
#endif
