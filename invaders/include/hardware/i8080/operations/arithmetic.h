#ifndef INVADERS_ARITHMETIC_H
#define INVADERS_ARITHMETIC_H

#include "operation.h"
#include "hardware/i8080/flags.h"
#include "hardware/i8080/registers.h"

namespace hardware {
    class Arithmetic: public Operation {
    public:
        Arithmetic(Flags& flags, Memory& memory, Registers& registers);
        ~Arithmetic() = default;

        void execute(byte opcode) override;

        void add(byte data);
        void subtract(byte data);
        void increment(byte dst);
        void decrement(byte dst);
        void dad(byte src);
        void daa();
    };
}
#endif
