#ifndef INVADERS_IN_H
#define INVADERS_IN_H

#include "opcode.h"

class IN: public OpCode {
public:
    IN() = delete;
    ~IN() = default;
    IN(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {

    }
};
#endif
