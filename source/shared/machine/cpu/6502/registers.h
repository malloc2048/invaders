#ifndef NESEMU_REGISTERS_H
#define NESEMU_REGISTERS_H

#include <cstdint>

class Registers {
public:
    Registers() = default;
    ~Registers() = default;

    uint16_t pc;
    uint8_t sp;
    uint8_t a;
    uint8_t x;
    uint8_t y;
};
#endif
