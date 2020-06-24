#ifndef INVADERS_Return_H
#define INVADERS_Return_H

#include "opcode.h"

class Return: public Instruction {
public:
    Return() = delete;
    ~Return() = default;
    Return(Flags& flags, Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        bool takeJump = true;

        if((opcode & 0x007u) == 0u) { // the lower 3 bits of the opcode == 0 this is a conditional return
            uint8_t condition = (opcode & 0x038u) >> 3u;
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

        if(takeJump)
            ret();
        else
            registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
    }

protected:
    void ret() {
        RegisterPair address{};
        address.bytes.low = memory.read_byte(registers.sp.d16);
        address.bytes.high = memory.read_byte(registers.sp.d16 + 1);
        registers.pc.d16 = address.d16;
        registers.sp.d16 += 2;
    }
};
#endif
