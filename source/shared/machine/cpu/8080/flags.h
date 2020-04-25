#ifndef NESEMU_FLAGS_H
#define NESEMU_FLAGS_H

#include <cstdint>

union Flags {
    struct {
        uint8_t zero: 1;
        uint8_t sign: 1;
        uint8_t parity: 1;
        uint8_t carry: 1;
        uint8_t auxiliary: 1;
        uint8_t pad: 3;
    };
    uint8_t d8;
};
#endif
