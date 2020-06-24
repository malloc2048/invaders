#ifndef INVADERS_Unimplemented_H
#define INVADERS_Unimplemented_H

#include "instruction.h"

class Unimplemented: public Instruction {
public:
    Unimplemented() = delete;
    ~Unimplemented() = default;
    Unimplemented(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        printf("Unimplemented %02x", opcode);
        exit(222);
    }
};
#endif
