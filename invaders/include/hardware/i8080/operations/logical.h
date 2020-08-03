#ifndef INVADERS_LOGICAL_H
#define INVADERS_LOGICAL_H

#include "hardware/i8080/operations/operation.h"

namespace hardware {
    class Logical: public Operation {
    public:
        Logical(Flags& flags, Memory& memory, Registers& registers);
        ~Logical() = default;

        void execute(byte opcode) override;

        void ana(byte data);
        void xra(byte data);
        void ora(byte data);
        void compare(byte data);
    };
}
#endif
