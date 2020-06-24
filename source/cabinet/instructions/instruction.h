#ifndef INVADERS_INSTRUCTION_H
#define INVADERS_INSTRUCTION_H

#include "cabinet/constants.h"
#include "cabinet/flags.h"
#include "cabinet/memory.h"
#include "cabinet/registers.h"

class Instruction {
public:
    Instruction(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers);
    ~Instruction() = default;

    virtual void Execute(uint8_t opcode) = 0;

    void updateFlags(uint8_t value) ;
    static uint8_t calculateParity(uint8_t value);
    void updateCarry(uint8_t original, uint8_t updated) ;

protected:
    cabinet::Flags& flags;
    cabinet::Memory& memory;
    Registers& registers;
};
#endif
