#ifndef INVADERS_MVI_H
#define INVADERS_MVI_H

#include "opcode.h"

class MVI: public OpCode {
public:
    MVI() = delete;
    ~MVI() = default;

    MVI(Flags& flags, Memory& memory, Registers& registers): OpCode(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        auto r = (opcode & 0x38u) >> 3u;
        auto value = memory.read_byte(registers.pc.d16);

        switch(r) {
            case B:
                registers.bc.bytes.high = value;
                break;
            case C:
                registers.bc.bytes.low = value;
                break;
            case D:
                registers.de.bytes.high = value;
                break;
            case E:
                registers.de.bytes.low = value;
                break;
            case H:
                registers.hl.bytes.high = value;
                break;
            case L:
                registers.hl.bytes.low = value;
                break;
            case M:
                memory.write(registers.hl.d16, value);
                break;
            case A:
                registers.a = value;
                break;
            default:
                break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }
};
#endif
