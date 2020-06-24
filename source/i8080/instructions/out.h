#ifndef INVADERS_OUT_H
#define INVADERS_OUT_H

#include "opcode.h"

class OUT: public Instruction {
public:
    OUT() = delete;
    ~OUT() = default;
    OUT(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {}
};
#endif
