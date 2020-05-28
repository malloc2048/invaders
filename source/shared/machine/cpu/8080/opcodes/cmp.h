#ifndef EMULATOR_CMP_H
#define EMULATOR_CMP_H

#include "machine/cpu/8080/opcode.h"

class CMP: public OpCode {
public:
    CMP() = delete;
    ~CMP() = default;
    CMP(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint8_t src = opcode & 0x07u;

        uint16_t result;
        switch(src) {
            case B:
                result = registers->a - registers->bc.bytes.high;
                break;
            case C:
                result = registers->a - registers->bc.bytes.low;
                break;
            case D:
                result = registers->a - registers->de.bytes.high;
                break;
            case E:
                result = registers->a - registers->de.bytes.low;
                break;
            case H:
                result = registers->a - registers->hl.bytes.high;
                break;
            case L:
                result = registers->a - registers->hl.bytes.low;
                break;
            case M:
                result = registers->a - ram->read(registers->hl.d16);
                break;
            case A:
                result = registers->a - registers->a;
                break;
            default:
                result = registers->a;
                break;
        }
        updateFlags(result);
        updateCarry(registers->a, result);
        flags->carry = result < 0 ? 1 : 0;
//        registers->a = result & 0x00ffu;

        return 1;
    }

    void Disassemble(std::ostream& out) override {
        auto src = ram->read(registers->pc.d16) & 0x07u;
        out << std::hex << (unsigned)ram->read(registers->pc.d16) << "\tCMP " << registerNames[src];
        registers->pc.d16 += 1;
    }
};
#endif
