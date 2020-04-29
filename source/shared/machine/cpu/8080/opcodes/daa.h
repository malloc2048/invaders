#ifndef NESEMU_DAA_H
#define NESEMU_DAA_H

#include "cpu/8080/opcode.h"

class DAA: public OpCode {
public:
    DAA() = default;
    ~DAA() = default;
    DAA(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        union Byte{
            struct {
                uint8_t low:4;
                uint8_t high:4;
            } bits;
            uint8_t d8;
        };

        Byte byte {};
        byte.d8 = registers->a;

        if(byte.bits.low > 9)
            byte.bits.low += 6;
        if(byte.bits.high > 9)
            byte.bits.high += 6;

        updateFlags(registers->a);
        updateAuxiliaryCarry(registers->a, byte.d8);
        flags->carry = byte.d8 < registers->a ? 1 : 0;
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tDAA";
        registers->pc.d16 += 1;


    }
};
#endif
