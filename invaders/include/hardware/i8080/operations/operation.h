#ifndef INVADERS_OPERATION_H
#define INVADERS_OPERATION_H

#include "hardware/constants.h"
#include "hardware/i8080/flags.h"
#include "hardware/i8080/memory.h"
#include "hardware/i8080/registers.h"

namespace hardware {
    class Operation {
    public:
        enum DATA_SRC_DST {
            B = 0,
            C = 1,
            D = 2,
            E = 3,
            H = 4,
            L = 5,
            M = 6,
            A = 7,
            BC = 8,
            DE = 9,
            HL = 10,
            SP = 11
        };

        Operation() = delete;
        ~Operation() = default;
        Operation(Flags& flags, Memory& memory, Registers& registers);

        byte nextByte() const;
        word getData(byte src) const;
        void setData(byte dst, word data);

        virtual void execute(byte opcode) = 0;

    protected:
        Flags& flags;
        Memory& memory;
        Registers& registers;
    };
}
#endif
