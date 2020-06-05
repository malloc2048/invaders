#ifndef INVADERS_MEMORY_H
#define INVADERS_MEMORY_H

#include <cstdint>
#include <istream>

class Memory {
public:
    Memory() = default;
    ~Memory() = default;

    void loadRom(FILE* romFile);
    uint8_t readByte(uint16_t address) const;
    uint16_t readWord(uint16_t address) const;
    void write(uint16_t address, uint8_t value);

    static const uint16_t ROM_SIZE = 0x2000;

private:
    uint8_t memory[0x10000] = {0};
};
#endif
