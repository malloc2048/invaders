#ifndef EMULATOR_MEMORYMAP_H
#define EMULATOR_MEMORYMAP_H

#include "cpu/8080/registers.h"

class MemoryMap {
public:
    MemoryMap() = default;
    ~MemoryMap() = default;

    uint8_t Read(uint16_t address) { return memory[address]; };
    bool Write(uint16_t address, uint8_t value);

    uint8_t ReadA() const{ return accumulator; }
    uint8_t ReadB() const{ return bc.byte.high; }
    uint8_t ReadC() const{ return bc.byte.low; }
    uint8_t ReadD() const{ return de.byte.high; }
    uint8_t ReadE() const{ return de.byte.low; }
    uint8_t ReadH() const{ return hl.byte.high; }
    uint8_t ReadL() const{ return hl.byte.low; }

    void WriteA(uint8_t value) { accumulator = value; };
    void WriteB(uint8_t value) { bc.byte.high = value; };
    void WriteC(uint8_t value) { bc.byte.low = value; };
    void WriteD(uint8_t value) { de.byte.high = value; };
    void WriteE(uint8_t value) { de.byte.low = value; };
    void WriteH(uint8_t value) { hl.byte.high = value; };
    void WriteL(uint8_t value) { hl.byte.low = value; };

private:
    RegisterPair bc;
    RegisterPair de;
    RegisterPair hl;
    RegisterPair pc;
    RegisterPair sp;
    uint8_t accumulator;
    ProcessorStatusWord psw;
    uint8_t interrupt_enable;

    uint8_t memory[65536];

    static const uint16_t ROM_MIN_ADDRESS;
    static const uint16_t ROM_MAX_ADDRESS;
    static const uint16_t RAM_MIN_ADDRESS;
    static const uint16_t RAM_MAX_ADDRESS;
    static const uint16_t VIDEO_RAM_MIN_ADDRESS;
    static const uint16_t VIDEO_RAM_MAX_ADDRESS;
};
#endif
