#ifndef EMULATOR_MVI_H
#define EMULATOR_MVI_H

#include "machine/cpu/8080/opcode.h"

class MVI: public OpCode {
public:
    MVI() = delete;
    ~MVI() = default;

    MVI(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        auto r = (opcode & 0x38u) >> 3u;
        auto value = ram->read(registers->pc.d16 + 1);

        debug << "move immediate " << registerNames[r] << " ";
        debug << std::hex << std::setw(2) << std::setfill('0') << value;
        switch(r) {
            case B:
                registers->bc.bytes.high = value;
                break;
            case C:
                registers->bc.bytes.low = value;
                break;
            case D:
                registers->de.bytes.high = value;
                break;
            case E:
                registers->de.bytes.low = value;
                break;
            case H:
                registers->hl.bytes.high = value;
                break;
            case L:
                registers->hl.bytes.low = value;
                break;
            case M:
                ram->write(registers->hl.d16, value);
                break;
            case A:
                registers->a = value;
                break;
            default:
                break;
        }
        return 2;
    }

    void Disassemble(std::ostream& out) override {
        auto r = (ram->read(registers->pc.d16) & 0x38u) >> 3u;

        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16);
        out << "\tMVI " << registerNames[r] << ", " << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 2;
    }
};
#endif
