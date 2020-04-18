#ifndef EMULATOR_REGISTERS_H
#define EMULATOR_REGISTERS_H

#include <cstdint>

struct Flags {
    uint8_t z:1;    // zero - set when operation result = 0
    uint8_t s:1;    // sign - set when MSB of operation result = 1
    uint8_t p:1;    // parity - set when operation result has even parity (sum of bits MOD 2 = 0)
    uint8_t cy:1;   // carry - set when instruction resulted in a carry or borrow from high order bit
    uint8_t ac:1;   // auxiliary carry - set when operation caused a carry out of bit 3 and into bit 4
    uint8_t pad:3;
};

union PSW {
    Flags flags;
    uint8_t psw;
};

struct Bytes {
    uint8_t lowByte: 8;
    uint8_t highByte: 8;
};

union pair {
    Bytes d8;
    uint16_t d16;
};

struct Registers {
    uint8_t a;          // accumulator
    pair bc;
    pair de;
    pair hl;
    pair pc;
    pair sp;

    uint8_t* memory;    // volatile memory
    PSW psw;        // flags
    uint8_t int_enable; // interrupt enabled?
    uint16_t shift;     // shift register
};
#endif
