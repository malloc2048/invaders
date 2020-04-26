#ifndef NESEMU_CMA_H
#define NESEMU_CMA_H

#include "cpu/8080/opcode.h"

class CMA: public OpCode {
public:
    CMA() = delete;
    ~CMA() = default;
    CMA(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        for(size_t i = 0; i < 8; i++){
            registers->a = registers->a ^ (0x01u << i);
        }
        return 1;
    }

    void Disassemble(std::ostream& out) override {
        out << "CMA";
        registers->pc.d16 += 1;


    }
};
#endif
