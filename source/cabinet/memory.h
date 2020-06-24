#ifndef INVADERS_MEMORY_H
#define INVADERS_MEMORY_H

#include <cstdint>
#include <fstream>

namespace cabinet {
    class Memory {
    public:
        Memory() = default;
        ~Memory() = default;

        void load_rom(std::ifstream &rom_file);
        uint8_t read_byte(uint16_t address) const;
        uint16_t read_word(uint16_t address) const;
        void write(uint16_t address, uint8_t value);

        static const uint16_t ROM_SIZE = 0x2000;

    private:
        uint8_t memory[0x10000] = {0};
    };
}
#endif
