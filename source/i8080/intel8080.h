#ifndef INVADERS_INTEL8080_H
#define INVADERS_INTEL8080_H

#include <cstdio>
#include "flags.h"
#include "opcodes.h"
#include "registers.h"
#include "memory/memory.h"
#include "i8080/instruction.h"

class Intel8080 {
public:
    explicit Intel8080(Memory& memoryIn);
    Intel8080() = delete;
    ~Intel8080() = default;

    void step();
    void interrupt(uint16_t address);

    uint16_t getPC() const;
    void incrementPC(uint16_t inc);

    uint8_t getAccumulator() const;
    void setAccumulator(uint8_t value);

    uint64_t getCycleCount() const;
    void setCycleCount(uint32_t value);

    uint8_t nextByte();

protected:
    void init();
    uint16_t nextWord();
    void initializeInstructions();

private:
    bool halted = true;
    OpCode* opcodes[256]{};
    unsigned long cycles = 0;

    Flags flags;
    Memory& memory;
    Registers registers;

    bool interruptPending = false;
    uint8_t interruptVector = 0x00;

    void debug() const;
    FILE* log = fopen(LOG_FILENAME().c_str(), "w");

    std::map<uint8_t, Instruction> instructions;
};
#endif
