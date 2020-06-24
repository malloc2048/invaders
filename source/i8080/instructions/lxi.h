#ifndef INVADERS_LXI_H
#define INVADERS_LXI_H

#include "opcode.h"

class LXI: public Instruction {
public:
    LXI() = delete;
    ~LXI() = default;

    LXI(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto rp = (opcode & 0x30u) >> 4u;
        switch(rp) {
            case BC:
                registers.bc.bytes.low = memory.read_byte(registers.pc.d16);
                registers.bc.bytes.high = memory.read_byte(registers.pc.d16 + 1);
                break;
            case DE:
                registers.de.bytes.low = memory.read_byte(registers.pc.d16);
                registers.de.bytes.high = memory.read_byte(registers.pc.d16 + 1);
                break;
            case HL:
                registers.hl.bytes.low = memory.read_byte(registers.pc.d16);
                registers.hl.bytes.high = memory.read_byte(registers.pc.d16 + 1);
                break;
            case SP:
                registers.sp.bytes.low = memory.read_byte(registers.pc.d16);
                registers.sp.bytes.high = memory.read_byte(registers.pc.d16 + 1);
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
