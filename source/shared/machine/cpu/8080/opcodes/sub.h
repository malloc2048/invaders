#ifndef EMULATOR_SUB_H
#define EMULATOR_SUB_H

#include "machine/cpu/8080/opcode.h"

class SUB: public OpCode {
public:
    SUB() = delete;
    ~SUB() = default;
    SUB(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint8_t src = opcode & 0x07u;

        uint16_t sum;
        switch(src) {
            case B:
                sum = registers->a - registers->bc.bytes.high;
                break;
            case C:
                sum = registers->a - registers->bc.bytes.low;
                break;
            case D:
                sum = registers->a - registers->de.bytes.high;
                break;
            case E:
                sum = registers->a - registers->de.bytes.low;
                break;
            case H:
                sum = registers->a - registers->hl.bytes.high;
                break;
            case L:
                sum = registers->a - registers->hl.bytes.low;
                break;
            case M:
                sum = registers->a - ram->read(registers->hl.d16);
                break;
            case A:
                sum = registers->a - registers->a;
                break;
            default:
                sum = registers->a;
                break;
        }
        updateFlags(sum);
        updateCarry(registers->a, sum);
        flags->carry = (sum & 0xff00u) != 0 ? 1 : 0;
        registers->a = sum & 0x00ffu;

        return 1;
    }

    void Disassemble(std::ostream& out) override {
        uint8_t src = ram->read(registers->pc.d16) & 0x07u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tSUB " << registerNames[src];
        registers->pc.d16 += 1;
    }
};

#endif
