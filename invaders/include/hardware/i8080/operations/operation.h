#ifndef INVADERS_OPERATION_H
#define INVADERS_OPERATION_H

#include "hardware/constants.h"
#include "hardware/i8080/flags.h"
#include "hardware/i8080/memory.h"
#include "hardware/i8080/registers.h"

namespace hardware {
    class Operation {
    public:
        Operation() = delete;
        ~Operation() = default;
        Operation(Flags& flags, Memory& memory, Registers& registers);

        byte nextByte() const;
        word nextWord() const;
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
