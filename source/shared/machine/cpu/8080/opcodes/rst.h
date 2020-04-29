#ifndef NESEMU_RST_H
#define NESEMU_RST_H

#include "cpu/8080/opcode.h"

class RST: public OpCode {
public:
    RST() = delete;
    ~RST() = default;
    RST(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        uint8_t number = (opcode & 0x038u) >> 3u;

        RegisterPair nextAddr{};
        nextAddr.d16 = registers->pc.d16 + 1;
        ram->write(registers->sp.d16 - 1, nextAddr.bytes.high);
        ram->write(registers->sp.d16 - 2, nextAddr.bytes.low);
        registers->sp.d16 -= 2;
        registers->pc.d16 = 8 * number;

        return 0;
    }

    void Disassemble(std::ostream& out) override {
        uint8_t number = (ram->read(registers->pc.d16) & 0x038u) >> 3u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tRST " << (unsigned)number;
        registers->pc.d16 += 1;
    }

protected:
    void ret() {
        RegisterPair address{};
        address.bytes.low = ram->read(registers->sp.d16);
        address.bytes.high = ram->read(registers->sp.d16 + 1);
        registers->pc.d16 = address.d16;
        registers->sp.d16 += 2;
    }
};

#endif
