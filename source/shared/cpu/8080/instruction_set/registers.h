#ifndef EMULATOR_REG_H
#define EMULATOR_REG_H

#include <cstdio>
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

struct Regs {
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

    void Dump() const {
        printf("registers:\n");
        printf("registers:\ta: %02x\n", a);
        printf("registers:\tbc: %04x\n", bc.d16);
        printf("registers:\t\tb: %02x\n", bc.d8.highByte);
        printf("registers:\t\tc: %02x\n", bc.d8.lowByte);
        printf("registers:\tde: %04x\n", de.d16);
        printf("registers:\t\td: %02x\n", de.d8.highByte);
        printf("registers:\t\te: %02x\n", de.d8.lowByte);
        printf("registers:\thl: %04x\n", hl.d16);
        printf("registers:\t\th: %02x\n", hl.d8.highByte);
        printf("registers:\t\tl: %02x\n", hl.d8.lowByte);
        printf("registers:\tpc: %04x\n", pc.d16);
        printf("registers:\tsp: %04x\n", sp.d16);
        printf("registers:\tmemory 0x0910: %02x\n", memory[0x0910]);
    }
};
#endif
