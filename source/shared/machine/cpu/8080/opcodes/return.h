#ifndef NESEMU_Return_H
#define NESEMU_Return_H

#include "cpu/8080/opcode.h"

class Return: public OpCode {
public:
    Return() = delete;
    ~Return() = default;
    Return(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t condition = (opcode & 0x038u) >> 3u;

        // the lower 3 bits of the opcode == 0 this is a conditional return
        if((opcode & 0x007u) == 0u) {
            switch(condition) {
                case NotZero:
                    if(flags->zero == 0) {
                        ret();
                        return 0;
                    }
                case Zero:
                    if(flags->zero == 1) {
                        ret();
                        return 0;
                    }
                case NoCarry:
                    if(flags->carry == 0) {
                        ret();
                        return 0;
                    }
                case Carry:
                    if(flags->carry == 1) {
                        ret();
                        return 0;
                    }
                case ParityOdd:
                    if(flags->parity == 0) {
                        ret();
                        return 0;
                    }
                case ParityEven:
                    if(flags->parity == 1) {
                        ret();
                        return 0;
                    }
                case Plus:
                    if(flags->sign == 0) {
                        ret();
                        return 0;
                    }
                case Minus:
                    if(flags->sign == 1) {
                        ret();
                        return 0;
                    }
                default:
                    return 3;
            }
        }

        // only get here if this is a no condition return
        ret();
        return 0;
    }

protected:
    void ret() {
        RegisterPair address{};
        address.bytes.low = ram->read(registers->sp.d16);
        address.bytes.high = ram->read(registers->sp.d16 + 1);
        registers->pc.d16 = address.d16;
        registers->sp.d16 += 2;
    }
};

#endif
