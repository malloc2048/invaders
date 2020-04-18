#ifndef EMULATOR_INTEL8080_H
#define EMULATOR_INTEL8080_H

#include <cstdint>
#include "instruction_set/registers.h"
#include "instruction_set/registers.h"

class Intel8080 {
public:
    Intel8080() = delete;
    ~Intel8080();
    explicit Intel8080(uint64_t memorySize);

    void Emulate8080();
    void Run(long bufferLength);

    Registers registers;

private:
    typedef void (*instruction)(Registers&);
    static instruction instructionSet[256];
};
#endif
