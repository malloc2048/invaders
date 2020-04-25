#ifndef NESEMU_CMA_H
#define NESEMU_CMA_H

#include "cpu/8080/opcode.h"

class CMA: public OpCode {
public:
    CMA() = delete;
    ~CMA() = default;
    CMA(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        for(size_t i = 0; i < 8; i++){
            registers->a = registers->a ^ (0x01u << i);
        }
        return 1;
    }
};
#endif
