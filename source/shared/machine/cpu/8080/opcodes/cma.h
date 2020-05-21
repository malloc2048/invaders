#ifndef EMULATOR_CMA_H
#define EMULATOR_CMA_H

#include "machine/cpu/8080/opcode.h"

class CMA: public OpCode {
public:
    CMA() = delete;
    ~CMA() = default;
    CMA(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        for(size_t i = 0; i < 8; i++){
            registers->a = registers->a ^ (0x01u << i);
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tCMA";
        registers->pc.d16 += 1;
    }
};
#endif
