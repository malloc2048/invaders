#ifndef NESEMU_FLAGS_H
#define NESEMU_FLAGS_H

#include <cstdint>

class Flags {
public:
    uint8_t c:1; // overflow in bit 7
    uint8_t z:1; //
    uint8_t i:1; // interrupt enabled
    uint8_t d:1; // decimal mode
    uint8_t b:1; // break command
    uint8_t v:1; // set if sign bit is incorrect
    uint8_t n:1; // set if bit 7 is set
    uint8_t pad:1;
};
#endif
