#ifndef INVADERS_CABINET_H
#define INVADERS_CABINET_H

#include "memory.h"
#include "constants.h"
#include "i8080/cpu.h"

namespace hardware {
    class Cabinet {
    public:
        Cabinet();
        ~Cabinet() = default;

        word getPC() const ;
        qword getCycleCount() const;
        void interrupt(word address);
        void setCycleCount(word count);

        byte getAccumulator() const;
        void setAccumulator(byte value);
        void incrementPC(byte increment);

        Memory memory;
        CPU cpu;

        byte nextInterrupt = 0x08;
        byte screenBuffer[256][224][4]{};

        // space invaders ports and shift registers
        byte port1 = 0x08, port2 = 0x03;
        byte shift0 = 0, shift1 = 0, shiftOffset = 0;
    };
}
#endif
