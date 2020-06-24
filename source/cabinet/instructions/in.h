#ifndef INVADERS_IN_H
#define INVADERS_IN_H

#include "instruction.h"

class IN: public Instruction {
public:
    IN() = delete;
    ~IN() = default;
    IN(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {

    }
};
#endif
