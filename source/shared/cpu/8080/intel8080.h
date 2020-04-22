#ifndef EMULATOR_INTEL8080_H
#define EMULATOR_INTEL8080_H

#include <cstdint>
#include "instruction_set/registers.h"

class Intel8080 {
public:
    Intel8080();
    ~Intel8080();

    void Emulate8080();
    void Run(long bufferLength);

    Regs registers;

protected:
    void debug();

private:
    typedef void (*instruction)(Regs&);
    static instruction instructionSet[256];
};
#endif
