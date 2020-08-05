#ifndef INVADERS_MEMORY_H
#define INVADERS_MEMORY_H

#include <fstream>
#include "hardware/constants.h"

namespace hardware {
    class Memory {
    public:
        Memory() = default;
        ~Memory() = default;

        void load_rom(std::ifstream &rom_file);

        byte read_byte(word address) const;
        word read_word(word address) const;
        void write(word address, byte value);
        void write_word(word address, word value);

        static const uint16_t ROM_SIZE = 0x2000;

    private:
        byte memory[0x10000] = {0};
    };
}
#endif
