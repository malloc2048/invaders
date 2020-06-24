#ifndef INVADERS_IN_H
#define INVADERS_IN_H

#include "opcode.h"

class IN: public Instruction {
public:
    IN() = delete;
    ~IN() = default;
    IN(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {

    }
};
#endif
