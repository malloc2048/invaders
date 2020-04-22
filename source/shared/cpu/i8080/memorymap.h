#ifndef EMULATOR_MEMORYMAP_H
#define EMULATOR_MEMORYMAP_H

#include "cpu/8080/instruction_set/registers.h"

union RegisterPair {
    uint16_t d16;
    struct {
        uint8_t low;
        uint8_t high;
    };
};

union ProcessorStatusWord {
    uint8_t psw;
    struct {
        uint8_t zero:1;         // zero - set when operation result = 0
        uint8_t sign:1;         // sign - set when MSB of operation result = 1
        uint8_t parity:1;       // parity - set when operation result has even parity (sum of bits MOD 2 = 0)
        uint8_t carry:1;        // carry - set when instruction resulted in a carry or borrow from high order bit
        uint8_t auxiliary:1;    // auxiliary carry - set when operation caused a carry out of bit 3 and into bit 4
        uint8_t pad:3;
    };
};

class MemoryMap {
public:
    MemoryMap() = default;
    ~MemoryMap() = default;

    uint8_t read(uint16_t address) { return memory[address]; };
    bool write(uint16_t address, uint8_t value);

    uint8_t ReadB() const{ return bc.high; }
    uint8_t ReadC() const{ return bc.low; }
    uint8_t ReadD() const{ return de.high; }
    uint8_t ReadE() const{ return de.low; }
    uint8_t ReadH() const{ return hl.high; }
    uint8_t ReadL() const{ return hl.low; }

    void WriteB(uint8_t value) { bc.high = value; };
    void WriteC(uint8_t value) { bc.low = value; };
    void WriteD(uint8_t value) { de.high = value; };
    void WriteE(uint8_t value) { de.low = value; };
    void WriteH(uint8_t value) { hl.high = value; };
    void WriteL(uint8_t value) { hl.low = value; };

private:
    RegisterPair bc;
    RegisterPair de;
    RegisterPair hl;
    RegisterPair pc;
    RegisterPair sp;
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
