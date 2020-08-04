#include "hardware/i8080/memory.h"

void hardware::Memory::load_rom(std::ifstream &rom_file) {
    if (rom_file.is_open()) {
        rom_file.read((char *) memory, ROM_SIZE);
    }
}

byte hardware::Memory::read_byte(word address) const {
    return memory[address];
}

word hardware::Memory::read_word(word address) const {
    word data = memory[address] | (memory[address + 1] << 0x08u);
    return data;
}

void hardware::Memory::write(word address, byte value) {
    if (address >= ROM_SIZE) {
        memory[address] = value;
    } else {
        fprintf(stdout, "attempt to write to ROM %04x\n", address);
    }
}

void hardware::Memory::write_word(word address, word value) {
    write(address, value & 0xffu);
    write(address + 1, (value & 0xff00u) >> 0x08 );
}
