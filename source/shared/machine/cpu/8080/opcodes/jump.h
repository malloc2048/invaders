#ifndef EMULATOR_JUMP_H
#define EMULATOR_JUMP_H

#include <map>
#include "machine/cpu/8080/opcode.h"

class Jump: public OpCode {
public:
    Jump() = delete;
    ~Jump() = default;
    Jump(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        bool takeJump = true;
        if((opcode & 0x007u) == 2u) {   // the lower 3 bits of the opcode == 2 this is a conditional jump
            debug << "conditional jump ";
            std::bitset<8> opcodeBits(opcode);
            uint8_t condition = (opcode & 0x38u) >> 3u;
            switch(condition) {
                case NotZero:       takeJump = flags->zero == 0; debug << "not zero, "; break;
                case Zero:          takeJump = flags->zero == 1; debug << "zero, "; break;
                case NoCarry:       takeJump = flags->carry == 0; debug << "no carry, "; break;
                case Carry:         takeJump = flags->carry == 1; debug << "carry, "; break;
                case ParityOdd:     takeJump = flags->parity == 0; debug << "odd parity, "; break;
                case ParityEven:    takeJump = flags->parity == 1; debug << "even parity, "; break;
                case Plus:          takeJump = flags->sign == 0; debug << "positive, "; break;
                case Minus:         takeJump = flags->sign == 1; debug << "negative, "; break;
                default:            return 3;
            }
        } else {
            debug << "unconditional jump, ";
        }

        if(takeJump) {
            jump(debug);
            return 0;
        }
        else{
            debug << "not taken";
            return 3;
        }
    }

    void Disassemble(std::ostream& out) override {
        uint8_t condition = (ram->read(registers->pc.d16) & 0x03fu) >> 3u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tJ";

        if((ram->read(registers->pc.d16) & 0x007u) == 2u) {
            out << OpCode::conditionStr[condition] << " ";
        } else {
            out << "MP ";
        }
        out << (unsigned)ram->read(registers->pc.d16 + 2) << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;
    }

protected:
    void jump(std::ostream& debug) {
        RegisterPair address{};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->pc.d16 = address.d16;

        debug << std::hex << std::setw(4) << std::setfill('0') << address.d16;
    }
};
#endif
