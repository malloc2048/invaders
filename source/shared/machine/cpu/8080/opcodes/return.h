#ifndef EMULATOR_Return_H
#define EMULATOR_Return_H

#include "machine/cpu/8080/opcode.h"

class Return: public OpCode {
public:
    Return() = delete;
    ~Return() = default;
    Return(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        bool takeJump = true;

        if((opcode & 0x007u) == 0u) { // the lower 3 bits of the opcode == 0 this is a conditional return
            debug << "conditional return ";

            uint8_t condition = (opcode & 0x038u) >> 3u;
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
            debug << "unconditional return, ";
        }

        if(takeJump) {
            ret(debug);
            return 0;
        }
        else{
            debug << "not taken";
            return 1;
        }
    }

    void Disassemble(std::ostream& out) override {
        uint8_t condition = ram->read(registers->pc.d16) & 0x038u >> 3u;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tR";

        if((ram->read(registers->pc.d16) & 0x007u) == 0u) {
            out << OpCode::conditionStr[condition] << " ";
        } else {
            out << "ET ";
        }
        registers->pc.d16 += 1;
    }

protected:
    void ret(std::ostream& debug) {
        RegisterPair address{};
        address.bytes.low = ram->read(registers->sp.d16);
        address.bytes.high = ram->read(registers->sp.d16 + 1);
        registers->pc.d16 = address.d16;
        registers->sp.d16 += 2;

        debug << std::hex << std::setw(4) << std::setfill('0') << address.d16;
    }
};
#endif
