#ifndef INVADERS_OUT_H
#define INVADERS_OUT_H

#include "opcode.h"

class OUT: public OpCode {
public:
    OUT() = delete;
    ~OUT() = default;
    OUT(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {}
};
#endif
