#ifndef NESEMU_ROTATE_H
#define NESEMU_ROTATE_H

#include "cpu/8080/opcode.h"

class Rotate: public OpCode {
public:
    Rotate() = delete;
    ~Rotate() = default;

    Rotate(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        switch(opcode) {
            case 0x07:  // RLC
                flags->carry = (registers->a & 0x80u) > 0 ? 1 : 0;
                registers->a = (unsigned)registers->a << 0x01u & flags->carry;
                break;
            case 0x0f:  // RRC
                flags->carry = (registers->a & 0x01u);
                registers->a = (unsigned)registers->a >> 0x01u;
                registers->a &= flags->carry == 0 ? 0x7fu : 0xffu;
                break;
            case 0x17: { // RAL
                auto bit7 = (registers->a & 0x80u) > 0 ? 1 : 0;
                registers->a = (unsigned) registers->a << 0x01u & flags->carry;
                flags->carry = bit7 > 0 ? 1 : 0;
                break;
            }
            case 0x1f: { // RAR
                auto bit0 = registers->a & 0x01u;
                registers->a = (unsigned) registers->a >> 0x01u;
                registers->a &= flags->carry == 0 ? 0x7fu : 0xffu;
                flags->carry = bit0;
                break;
            }
            default:
                break;
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\t";

        auto opcode = ram->read(registers->pc.d16);
        switch(opcode) {
            case 0x07:  // RLC
                out << "RLC";
                break;
            case 0x0f:  // RRC
                out << "RRC";
                break;
            case 0x17:  // RAL
                out << "RAL";
                break;
            case 0x1f:  // RAR
                out << "RAR";
                break;
            default:
                break;
        }

        registers->pc.d16 += 1;


    }
};

#endif
