#ifndef INVADERS_STAX_H
#define INVADERS_STAX_H

#include "opcode.h"

class STAX: public OpCode {
public:
    STAX() = delete;
    ~STAX() = default;

    STAX(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        switch(rp) {
            case BC:
                memory.write(registers.bc.d16, registers.a);
                break;
            case DE:
                memory.write(registers.de.d16, registers.a);
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
