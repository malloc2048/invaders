#ifndef INVADERS_INTEL8080_H
#define INVADERS_INTEL8080_H

#include "flags.h"
#include "memory.h"
#include "registers.h"
#include "instructions/instructions.h"

namespace cabinet {
    class Intel8080 {
    public:
        explicit Intel8080(Memory &memoryIn);
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
        void initializeInstructions();

    private:
        Instruction *opcodes[256]{};
        unsigned long cycles = 0;

        Flags flags;
        Memory &memory;
        Registers registers;
    };
}
#endif
