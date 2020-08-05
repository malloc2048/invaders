#ifndef INVADERS_DATA_TRANSFER_H
#define INVADERS_DATA_TRANSFER_H

#include "hardware/i8080/operations/operation.h"

namespace hardware {
    class DataTransfer: public Operation {
    public:
        DataTransfer(Flags& flags, Memory& memory, Registers& registers);
        ~DataTransfer() = default;

        void execute(byte opcode) override;
    };
}
#endif
