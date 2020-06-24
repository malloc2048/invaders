#ifndef INVADERS_CALL_H
#define INVADERS_CALL_H

#include "instruction.h"

class CALL: public Instruction {
public:
    CALL() = delete;
    ~CALL() = default;
    CALL(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {
        bool takeJump = true;

        if((opcode & 0x007u) == 0x04u) {    // the lower 3 bits of the opcode == 4 this is a conditional call
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
            call();
        } else {
            registers.pc.d16 += OPCODES_LENGTH[opcode] - 1;
        }
    }

protected:
    void call() {
        RegisterPair address{};
        address.d16 = registers.pc.d16 + 2;
        memory.write(registers.sp.d16 - 1, address.bytes.high);
        memory.write(registers.sp.d16 - 2, address.bytes.low);
        registers.sp.d16 -= 2;

        address.bytes.low = memory.read_byte(registers.pc.d16);
        address.bytes.high = memory.read_byte(registers.pc.d16 + 1);
        registers.pc.d16 = address.d16;
    }
};
#endif
