#ifndef EMULATOR_DCR_H
#define EMULATOR_DCR_H

#include "machine/cpu/8080/opcode.h"

class DCR: public OpCode {
public:
    DCR() = delete;
    ~DCR() = default;

    DCR(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        auto r = (opcode & 0x38u) >> 3u;

        uint8_t value;
        switch(r) {
            case B:
                value = registers->bc.bytes.high;
                registers->bc.bytes.high = value - 1;
                break;
            case C:
                value = registers->bc.bytes.low;
                registers->bc.bytes.low = value - 1;
                break;
            case D:
                value = registers->de.bytes.high;
                registers->de.bytes.high = value - 1;
                break;
            case E:
                value = registers->de.bytes.low;
                registers->de.bytes.low = value - 1;
                break;
            case H:
                value = registers->hl.bytes.high;
                registers->hl.bytes.high = value - 1;
                break;
            case L:
                value = registers->hl.bytes.low;
                registers->hl.bytes.low = value - 1;
                break;
            case M:
                value = ram->read(registers->hl.d16);
                ram->write(registers->hl.d16, value - 1);
                break;
            case A:
                value = registers->a;
                registers->a = value - 1;
                break;
            default:
                return 1;
        }

        updateFlags(value - 1);
        updateCarry(value, value - 1);

        std::bitset<8>psw(flags->d8);
        debug << "decrement register " << registerNames[r] << ": ";
        debug << std::hex << std::setfill('0') << std::setw(2) << ((value - 1u) & 0xffu) << " flags: " << psw;

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
