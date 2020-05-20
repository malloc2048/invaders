#ifndef EMULATOR_FLAGS_H
#define EMULATOR_FLAGS_H

#include <cstdint>

union Flags {
    struct {
        uint8_t zero: 1;
        uint8_t sign: 1;
        uint8_t parity: 1;
        uint8_t carry: 1;
        uint8_t halfCarry: 1;
        uint8_t pad: 3;
    };
    uint8_t d8 = 0x00;
};
#endif
