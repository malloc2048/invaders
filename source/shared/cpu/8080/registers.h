#ifndef EMULATOR_REGISTERS_H
#define EMULATOR_REGISTERS_H

#include <cstdint>

union RegisterPair {
    struct {
        uint8_t low: 8;
        uint8_t high: 8;
    } byte;
    uint16_t word:16;
};

union ProcessorStatusWord {
    uint8_t psw;
    struct {
        uint8_t zero:1;         // zero - set when operation result = 0
        uint8_t sign:1;         // sign - set when MSB of operation result = 1
        uint8_t parity:1;       // parity - set when operation result has even parity (sum of bits MOD 2 = 0)
        uint8_t carry:1;        // carry - set when instruction resulted in a carry or borrow from high order bit
        uint8_t auxiliary:1;    // auxiliary carry - set when operation caused a carry out of bit 3 and into bit 4
        uint8_t pad:3;
    };
};
#endif
