#ifndef NESEMU_RAM_H
#define NESEMU_RAM_H

#include <cstdint>

class RAM {
public:
    RAM() = default;
    ~RAM() = default;

    uint8_t read(uint16_t address) const;
    bool write(uint16_t address, uint8_t value);

private:
    uint8_t ram[65536];
};
#endif
