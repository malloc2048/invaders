#ifndef INVADERS_MOV_H
#define INVADERS_MOV_H

#include "opcode.h"

class MOV: public Instruction {
public:
    MOV() = delete;
    ~MOV() = default;
    MOV(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        uint8_t src = opcode & 0x07u;
        uint8_t dst = (opcode & 0x38u) >> 3u;

        switch(src) {
            case B:  move(dst, registers.bc.bytes.high); break;
            case C:  move(dst, registers.bc.bytes.low); break;
            case D:  move(dst, registers.de.bytes.high); break;
            case E:  move(dst, registers.de.bytes.low); break;
            case H:  move(dst, registers.hl.bytes.high); break;
            case L:  move(dst, registers.hl.bytes.low); break;
            case M:  move(dst, memory.read_byte(registers.hl.d16)); break;
            case A:  move(dst, registers.a); break;
            default: break;
        }
        registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }

    void move(uint8_t dst, uint8_t value) {
        switch(dst) {
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
    }
};

#endif
