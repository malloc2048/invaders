#ifndef NESEMU_JUMP_H
#define NESEMU_JUMP_H

#include "cpu/8080/opcode.h"

class Jump: public OpCode {
public:
    Jump() = delete;
    ~Jump() = default;
    Jump(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t condition = opcode & 0x03fu;

        // the lower 3 bits of the opcode == 2 this is a conditional jump
        if((opcode & 0x007u) == 0u) {
            switch(condition) {
                case NotZero:
                    if(flags->zero == 0) {
                        jump();
                        return 0;
                    }
                case Zero:
                    if(flags->zero == 1) {
                        jump();
                        return 0;
                    }
                case NoCarry:
                    if(flags->carry == 0) {
                        jump();
                        return 0;
                    }
                case Carry:
                    if(flags->carry == 1) {
                        jump();
                        return 0;
                    }
                case ParityOdd:
                    if(flags->parity == 0) {
                        jump();
                        return 0;
                    }
                case ParityEven:
                    if(flags->parity == 1) {
                        jump();
                        return 0;
                    }
                case Plus:
                    if(flags->sign == 0) {
                        jump();
                        return 0;
                    }
                case Minus:
                    if(flags->sign == 1) {
                        jump();
                        return 0;
                    }
                default:
                    return 3;
            }
        }

        // only get here if this is a no condition jump
        jump();
        return 0;
    }

    void Disassemble(std::ostream& out) override {
        uint8_t condition = ram->read(registers->pc.d16) & 0x03fu;

        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << "\tJ";

        if((ram->read(registers->pc.d16) & 0x007u) == 0u) {
            out << OpCode::conditionStr[condition] << " ";
        } else {
            out << "MP ";
        }
        out << (unsigned)ram->read(registers->pc.d16 + 2) << (unsigned)ram->read(registers->pc.d16 + 1);
        registers->pc.d16 += 3;


    }

protected:
    void jump() {
        RegisterPair address{};
        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->pc.d16 = address.d16;
    }
};

#endif
