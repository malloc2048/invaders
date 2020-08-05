#include "hardware/i8080/flags.h"

void hardware::Flags::calculateParity(byte value) {
    byte bitsSet = 0;
    for(auto i = 0; i < 8; i++) {
        if(value & (0x01u << i))
            bitsSet++;
    }
    parity = (bitsSet & 0x01u) == 0;
}
