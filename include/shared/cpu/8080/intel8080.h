#ifndef EMULATOR_INTEL8080_H
#define EMULATOR_INTEL8080_H

#include <cstdint>
#include "state.h"
#include "instructions/instruction.h"

class Intel8080 {
public:
    Intel8080() = default;
    ~Intel8080() = default;

    void Emulate8080();
    void Run(long bufferLength);

    State8080 state = {
        .a = 0, .b = 0, .c = 0, .d = 0, .e = 0, .h = 0, .l = 0, .sp = 0, .pc = 0,
        .memory = new uint8_t[sizeof(uint8_t) * 8],
        .cc = ConditionCodes{ .z = 0, .s = 0, .p = 0, .cy = 0, .ac = 0, .pad = 0}, .int_enable = 0
    };

private:
    Instruction instructionSet[256];
};
#endif
