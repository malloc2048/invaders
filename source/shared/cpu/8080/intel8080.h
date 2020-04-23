#ifndef EMULATOR_INTEL8080_H
#define EMULATOR_INTEL8080_H

#include <cstdint>
#include "memorymap.h"
#include "instruction_set/regs.h"

class Intel8080 {
public:
    Intel8080();
    ~Intel8080();

    void Emulate8080();
    void GenerateInterrupt(uint8_t intNumber);

    MemoryMap mm;
    Regs registers;

protected:
    void debug();

private:
    typedef void (*opcode)(MemoryMap&);
    static opcode opcodes[256];

    typedef void (*instruction)(Regs&);
    static instruction instructionSet[256];
};
#endif
