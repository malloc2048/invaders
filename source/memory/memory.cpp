#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

#include <iomanip>
#include <fstream>
#include "memory.h"

void Memory::load_rom(std::ifstream& rom_file) {
    if(rom_file.is_open()) {
        rom_file.read((char*)memory, ROM_SIZE);
    }
}

uint8_t Memory::read_byte(uint16_t address) const {
    return memory[address];
}

uint16_t Memory::read_word(uint16_t address) const {
    uint16_t word = read_byte(address);
    word |= read_byte(address + 1) << 8u;
    return word;
}

void Memory::write(uint16_t address, uint8_t value) {
    if(address >= ROM_SIZE) {
        memory[address] = value;
    } else {
        fprintf(stdout, "attempt to write to ROM %04x\n", address);
    }
}
