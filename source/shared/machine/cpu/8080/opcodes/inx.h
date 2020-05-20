#ifndef EMULATOR_INX_H
#define EMULATOR_INX_H

#include "machine/cpu/8080/opcode.h"

class INX: public OpCode {
public:
    INX() = delete;
    ~INX() = default;

    INX(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        auto rp = (opcode & 0x30u) >> 4u;
        debug << "increment content of register pair " << registerPairNames[rp];

        switch(rp) {
            case BC: registers->bc.d16 += 1; break;
            case DE: registers->de.d16 += 1; break;
            case HL: registers->hl.d16 += 1; break;
            case SP: registers->sp.d16 += 1; break;
            default: break;
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tINX " << registerPairNames[rp];
        registers->pc.d16 += 1;
    }
};
#endif
