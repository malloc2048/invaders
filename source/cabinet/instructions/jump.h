#ifndef INVADERS_JUMP_H
#define INVADERS_JUMP_H

#include <map>
#include <bitset>
#include "instruction.h"

class Jump: public Instruction {
public:
    Jump() = delete;
    ~Jump() = default;
    Jump(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        bool takeJump = true;
        if((opcode & 0x007u) == 2u) {   // the lower 3 bits of the opcode == 2 this is a conditional jump
            //std::bitset<8> opcodeBits(opcode);
            uint8_t condition = (opcode & 0x38u) >> 3u;
            switch(condition) {
                case NotZero:       takeJump = flags.zero == 0; break;
                case Zero:          takeJump = flags.zero == 1; break;
                case NoCarry:       takeJump = flags.carry == 0; break;
                case Carry:         takeJump = flags.carry == 1; break;
                case ParityOdd:     takeJump = flags.parity == 0; break;
                case ParityEven:    takeJump = flags.parity == 1; break;
                case Plus:          takeJump = flags.sign == 0; break;
                case Minus:         takeJump = flags.sign == 1; break;
                default:            break;
            }
        }

        if(takeJump) {
            jump();
        } else {
            registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
        }
    }

protected:
    void jump() {
        RegisterPair address{};
        address.bytes.low = memory.read_byte(registers.pc.d16);
        address.bytes.high = memory.read_byte(registers.pc.d16 + 1);
        registers.pc.d16 = address.d16;
    }
};
#endif
