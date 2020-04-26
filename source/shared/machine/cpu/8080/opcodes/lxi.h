#ifndef NESEMU_LXI_H
#define NESEMU_LXI_H

#include "cpu/8080/opcode.h"

class LXI: public OpCode {
public:
    LXI() = delete;
    ~LXI() = default;

    LXI(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
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

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tLXI " << registerPairNames[rp] << " "
           << (unsigned)ram->read(registers->pc.d16 + 2) << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;


    }
};
#endif
