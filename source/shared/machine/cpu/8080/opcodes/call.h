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

    int8_t Execute(uint8_t opcode) override {
        uint8_t condition = opcode & 0x03fu;

        // the lower 3 bits of the opcode == 4 this is a conditional call
        if((opcode & 0x007u) == 0x04u) {
            switch(condition) {
                case NotZero:
                    if(flags->zero == 0) {
                        call();
                        return 0;
                    }
                case Zero:
                    if(flags->zero == 1) {
                        call();
                        return 0;
                    }
                case NoCarry:
                    if(flags->carry == 0) {
                        call();
                        return 0;
                    }
                case Carry:
                    if(flags->carry == 1) {
                        call();
                        return 0;
                    }
                case ParityOdd:
                    if(flags->parity == 0) {
                        call();
                        return 0;
                    }
                case ParityEven:
                    if(flags->parity == 1) {
                        call();
                        return 0;
                    }
                case Plus:
                    if(flags->sign == 0) {
                        call();
                        return 0;
                    }
                case Minus:
                    if(flags->sign == 1) {
                        call();
                        return 0;
                    }
                default:
                    return 3;
            }
        }

        // only get here if this is a no condition call
        call();
        return 0;
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0') << (unsigned)ram->read(registers->pc.d16);
        out << "\tCALL " << (unsigned)ram->read(registers->pc.d16 + 1) << (unsigned)ram->read(registers->pc.d16 + 2);
        registers->pc.d16 += 3;
    }

protected:
    void call() {
        RegisterPair address{};
        ram->write(registers->sp.d16 - 1, registers->pc.bytes.high);
        ram->write(registers->sp.d16 - 2, registers->pc.bytes.low);
        registers->sp.d16 -= 2;

        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
        registers->pc.d16 = address.d16;
    }
};

#endif
