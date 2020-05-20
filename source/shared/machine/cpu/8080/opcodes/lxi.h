#ifndef EMULATOR_LXI_H
#define EMULATOR_LXI_H

#include "machine/cpu/8080/opcode.h"

class LXI: public OpCode {
public:
    LXI() = delete;
    ~LXI() = default;

    LXI(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        auto rp = (opcode & 0x30u) >> 4u;
//        debug << "load " << registerPairNames[rp] << " immediate ";
//        debug << std::hex << std::setw(4) << std::setfill('0');
        switch(rp) {
            case BC:
                registers->bc.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->bc.bytes.high = ram->read(registers->pc.d16 + 2);
                debug << registers->bc.d16;
                break;
            case DE:
                registers->de.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->de.bytes.high = ram->read(registers->pc.d16 + 2);
                debug << registers->de.d16;
                break;
            case HL:
                registers->hl.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->hl.bytes.high = ram->read(registers->pc.d16 + 2);
                debug << registers->hl.d16;
                break;
            case SP:
                registers->sp.bytes.low = ram->read(registers->pc.d16 + 1);
                registers->sp.bytes.high = ram->read(registers->pc.d16 + 2);
                debug << registers->sp.d16;
                break;
            default:
                break;
        }

        return 3;
    }

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16);
        out << "\tLXI " << registerPairNames[rp] << " ";
        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16 + 2);
        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;
    }
};
#endif
