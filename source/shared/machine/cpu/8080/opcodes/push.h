#ifndef NESEMU_PUSH_H
#define NESEMU_PUSH_H

#include "cpu/8080/opcode.h"

class PUSH: public OpCode {
public:
    PUSH() = delete;
    ~PUSH() = default;

    PUSH(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
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

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tPUSH ";

        if(rp != SP)
            out << registerPairNames[rp];
        else
            out << "PSW";
        registers->pc.d16 += 1;
    }
};
#endif
