#ifndef NESEMU_RAM_H
#define NESEMU_RAM_H

#include <cstdint>
#include <istream>

class RAM {
public:
    RAM() = default;
    ~RAM() = default;

    void lockRom();
    void loadRom();
    void loadRom(FILE* romFile);
    uint8_t read(uint16_t address) const;
    bool write(uint16_t address, uint8_t value);

    static const uint16_t ROM_MIN_ADDR = 0x0000;
    static const uint16_t ROM_MAX_ADDR = 0x2000;
    static const uint16_t MEM_MAX_ADDR = 0xffff;

private:
    uint8_t ram[MEM_MAX_ADDR];
    bool writeProtected = true;
};
#endif
