#ifndef INVADERS_CABINET_H
#define INVADERS_CABINET_H

#include "constants.h"
#include "memory/memory.h"
#include "i8080/intel8080.h"

class Cabinet {
public:
    Cabinet();
    ~Cabinet() = default;

    Memory memory;
    Intel8080 cpu;

    uint8_t nextInterrupt = 0x08;
    uint8_t screenBuffer[256][224][4]{};

    // space invaders ports and shift registers
    uint8_t port1 = 0x08, port2 = 0x03;
    uint8_t shift0 = 0, shift1 = 0, shiftOffset = 0;
};
#endif
