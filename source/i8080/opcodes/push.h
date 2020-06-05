#ifndef INVADERS_PUSH_H
#define INVADERS_PUSH_H

#include "opcode.h"

class PUSH: public OpCode {
public:
    PUSH() = delete;
    ~PUSH() = default;

    PUSH(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint8_t value;
        switch(rp) {
            case BC:
                memory.write(registers.sp.d16 - 1, registers.bc.bytes.high);
                memory.write(registers.sp.d16 - 2, registers.bc.bytes.low);
                registers.sp.d16 -= 2;
                break;
            case DE:
                memory.write(registers.sp.d16 - 1, registers.de.bytes.high);
                memory.write(registers.sp.d16 - 2, registers.de.bytes.low);
                registers.sp.d16 -= 2;
                break;
            case HL:
                memory.write(registers.sp.d16 - 1, registers.hl.bytes.high);
                memory.write(registers.sp.d16 - 2, registers.hl.bytes.low);
                registers.sp.d16 -= 2;
                break;
            case SP: // PUSH PSW - save the PSW
                memory.write(registers.sp.d16 - 1, registers.a);
                memory.write(registers.sp.d16 - 2, flags.d8);
                registers.sp.d16 -= 2;
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
