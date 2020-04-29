#ifndef NESEMU_LDAX_H
#define NESEMU_LDAX_H

#include "cpu/8080/opcode.h"

class LDAX: public OpCode {
public:
    LDAX() = delete;
    ~LDAX() = default;

    LDAX(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        auto rp = (opcode & 0x30u) >> 4u;
        debug << "load A from address in register pair " << registerPairNames[rp] << " ";
        debug << std::setfill('0') << std::setw(4) << std::hex;

        switch(rp) {
            case BC:
                registers->a = ram->read(registers->bc.d16);
                debug << registers->bc.d16;
                break;
            case DE:
                registers->a = ram->read(registers->de.d16);
                debug << registers->de.d16;
                break;
            default:
                break;
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        auto rp = (ram->read(registers->pc.d16) & 0x30u) >> 4u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tLDAX " << registerPairNames[rp];
        registers->pc.d16 += 1;
    }
};
#endif
