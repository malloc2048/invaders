#ifndef EMULATOR_REGISTERS_H
#define EMULATOR_REGISTERS_H

#include <cstdint>

class Registers {
public:
    Registers() = default;
    ~Registers() = default;

    uint8_t accumulator;

    union RegisterPair_BC {
        struct {
            uint8_t c: 8;
            uint8_t b: 8;
        };
        uint16_t bc:16;
    } bc;

    union RegisterPair_DE {
        struct {
            uint8_t e: 8;
            uint8_t d: 8;
        };
        uint16_t de:16;
    } de;
};
#endif
