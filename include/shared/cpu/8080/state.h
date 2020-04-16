#ifndef EMULATOR_STATE_H
#define EMULATOR_STATE_H

#include <cstdint>
#include "common/config.h"

typedef struct Flags {
    uint8_t z:1;    // zero - set when operation result = 0
    uint8_t s:1;    // sign - set when MSB of operation result = 1
    uint8_t p:1;    // parity - set when operation result has even parity (sum of bits MOD 2 = 0)
    uint8_t cy:1;   // carry - set when instruction resulted in a carry or borrow from high order bit
    uint8_t ac:1;   // auxiliary carry - set when operation caused a carry out of bit 3 and into bit 4
    uint8_t pad:3;
} ConditionCodes;

typedef struct State8080 {
    uint8_t a;          // accumulator
    uint8_t b;          // high order register of BC pair
    uint8_t c;          // low order register of BC pair
    uint8_t d;          // high order register of DE pair
    uint8_t e;          // low order register of DE pair
    uint8_t h;          // high order register of HL pair
    uint8_t l;          // low order register of HL pair
    uint16_t sp;        // stack pointer
    uint16_t pc;        // program counter
    uint8_t* memory;    // volatile memory
    Flags cc;           // flags
    uint8_t int_enable; // interrupt enabled?
} State8080;
#endif
