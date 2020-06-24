#ifndef INVADERS_OUT_H
#define INVADERS_OUT_H

#include "instruction.h"

class OUT: public Instruction {
public:
    OUT() = delete;
    ~OUT() = default;
    OUT(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {}
};
#endif
