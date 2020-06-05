#ifndef INVADERS_POP_H
#define INVADERS_POP_H

#include "opcode.h"

class POP: public OpCode {
public:
    POP() = delete;
    ~POP() = default;

    POP(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;

        uint8_t value;
        switch(rp) {
            case BC:
                registers.bc.bytes.low = memory.readByte(registers.sp.d16);
                registers.bc.bytes.high = memory.readByte(registers.sp.d16 + 1);
                registers.sp.d16 += 2;
                break;
            case DE:
                registers.de.bytes.low = memory.readByte(registers.sp.d16);
                registers.de.bytes.high = memory.readByte(registers.sp.d16 + 1);
                registers.sp.d16 += 2;
                break;
            case HL:
                registers.hl.bytes.low = memory.readByte(registers.sp.d16);
                registers.hl.bytes.high = memory.readByte(registers.sp.d16 + 1);
                registers.sp.d16 += 2;
                break;
            case SP: // POP PSW - restore the PSW
                flags.d8 = memory.readByte(registers.sp.d16);
                registers.a = memory.readByte(registers.sp.d16 + 1);
                registers.sp.d16 += 2;
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
