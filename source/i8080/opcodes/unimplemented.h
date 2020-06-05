#ifndef INVADERS_Unimplemented_H
#define INVADERS_Unimplemented_H

#include "opcode.h"

class Unimplemented: public OpCode {
public:
    Unimplemented() = delete;
    ~Unimplemented() = default;
    Unimplemented(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        printf("Unimplemented %02x", opcode);
        exit(222);
    }
};
#endif
