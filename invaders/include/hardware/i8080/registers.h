#ifndef INVADERS_REGISTERS_H
#define INVADERS_REGISTERS_H

#include "hardware/constants.h"

namespace hardware {
    struct Registers {
        byte readRegister(byte reg) const;
        word readRegisterPair(byte regPair) const;

        byte b = 0;
        byte c = 0;
        byte d = 0;
        byte e = 0;
        byte h = 0;
        byte l = 0;

        byte accumulator = 0;
        word stack_pointer = 0;
        word program_counter = 0;
    };
}
#endif
