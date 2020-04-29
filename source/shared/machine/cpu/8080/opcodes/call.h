#ifndef NESEMU_CALL_H
#define NESEMU_CALL_H

#include "cpu/8080/opcode.h"

class CALL: public OpCode {
public:
    CALL() = delete;
    ~CALL() = default;
    CALL(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        bool takeJump = true;

        if((opcode & 0x007u) == 0x04u) {    // the lower 3 bits of the opcode == 4 this is a conditional call
            debug << "conditional call ";
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
            debug << "unconditional call, ";
        }

        if(takeJump) {
            call(debug);
            return 0;
        }
        else{
            debug << "not taken";
            return 3;
        }
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16);
        out << "\tC";

        if((ram->read(registers->pc.d16) & 0x007u) == 0x04u) { // conditional call
            uint8_t condition = (ram->read(registers->pc.d16) & 0x38u) >> 3u;
            out << conditionStr[condition] << " ";
        } else {
            out << "ALL ";
        }
        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16 + 2);
        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;
    }

protected:
    void call(std::ostream& debug) {
        RegisterPair address{};
        address.d16 = registers->pc.d16 + 3;
        ram->write(registers->sp.d16 - 1, address.bytes.high);
        ram->write(registers->sp.d16 - 2, address.bytes.low);
        registers->sp.d16 -= 2;


        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->pc.d16 = address.d16;

        debug << std::hex << std::setw(4) << std::setfill('0') << address.d16;
    }
};

#endif
