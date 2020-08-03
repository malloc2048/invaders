#ifndef INVADERS_BRANCHING_H
#define INVADERS_BRANCHING_H

#include "hardware/i8080/operations/operation.h"

namespace hardware {
    class Branching: public Operation {
    public:
        Branching(Flags& flags, Memory& memory, Registers& registers);
        ~Branching() = default;

        void execute(byte opcode) override;

        void ret();
        void call();
        void restart(byte restartNum);
        bool checkCondition(byte condition);
    };
}
#endif
