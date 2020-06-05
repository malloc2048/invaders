#ifndef INVADERS_REGISTERS_H
#define INVADERS_REGISTERS_H

#include <cstdint>

enum RegisterPatterns {
    B = 0x00,
    C = 0x01,
    D = 0x02,
    E = 0x03,
    H = 0x04,
    L = 0x05,
    M = 0x06,
    A = 0x07,
};

enum RegisterPairPatterns {
    BC = 0x00,
    DE = 0x01,
    HL = 0x02,
    SP = 0x03,
};

union RegisterPair {
    uint16_t d16;
    struct {
        uint8_t low:8;
        uint8_t high:8;
    } bytes;
};

enum Conditions {
    NotZero     = 0x00,
    Zero        = 0x01,
    NoCarry     = 0x02,
    Carry       = 0x03,
    ParityOdd   = 0x04,
    ParityEven  = 0x05,
    Plus        = 0x06,
    Minus       = 0x07
};

class Registers {
public:
    Registers() = default;
    ~Registers() = default;

    uint8_t a = 0x00;
    RegisterPair pc = { 0x0000 };
    RegisterPair sp = { 0x0000 };
    RegisterPair bc = { 0x0000 };
    RegisterPair de = { 0x0000 };
    RegisterPair hl = { 0x0000 };

    bool halted = false;
    uint8_t interruptDelay = 0;
    bool interruptEnabled = false;
};
#endif
