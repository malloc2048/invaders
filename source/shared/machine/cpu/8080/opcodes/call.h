#ifndef NESEMU_CALL_H
#define NESEMU_CALL_H

#include "cpu/8080/opcode.h"

class CALL: public OpCode {
public:
    CALL() = delete;
    ~CALL() = default;
    CALL(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
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

protected:
    void call() {
        RegisterPair address{};
        ram->write(registers->sp.d16 - 1, registers->pc.bytes.high);
        ram->write(registers->sp.d16 - 2, registers->pc.bytes.low);
        registers->sp.d16 -= 2;

        address.bytes.low = ram->read(registers->pc.d16 + 1);
        address.bytes.high = ram->read(registers->pc.d16 + 2);
    }
};

#endif
