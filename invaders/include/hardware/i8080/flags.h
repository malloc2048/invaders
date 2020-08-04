#ifndef INVADERS_FLAGS_H
#define INVADERS_FLAGS_H

#include "hardware/constants.h"

namespace hardware {
    struct Flags {
        bool sign = false;
        bool zero = false;
        bool carry = false;
        bool parity = false;
        bool half_carry = false;

        bool halted = false;
        bool interruptEnabled = false;

        void calculateParity(byte value);
    };
}
#endif
