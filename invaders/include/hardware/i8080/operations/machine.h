#ifndef INVADERS_MACHINE_H
#define INVADERS_MACHINE_H

#include "hardware/i8080/operations/operation.h"

namespace hardware {
    class Machine: public Operation {
    public:
        Machine(Flags& flags, Memory& memory, Registers& registers);
        ~Machine() = default;

        void execute(byte opcode) override;

        void xthl();
        void setPSW();
        void pop(byte dst);
        word getPSW() const;
        void push(word data);
    };
}
#endif
