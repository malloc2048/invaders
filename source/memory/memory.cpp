#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

#include <iomanip>
#include <iostream>
#include "memory.h"

void Memory::loadRom(FILE* romFile) {
    fseek(romFile, 0L, SEEK_END);
    auto fileLength = ftell(romFile);
    fseek(romFile, 0L, SEEK_SET);
    fread(memory, sizeof(char), fileLength, romFile);
}

uint8_t Memory::readByte(uint16_t address) const {
    return memory[address];
}

uint16_t Memory::readWord(uint16_t address) const {
    uint16_t word = readByte(address);
    word |= readByte(address + 1) << 8u;
    return word;
}

void Memory::write(uint16_t address, uint8_t value) {
    if(address >= ROM_SIZE) {
        memory[address] = value;
    } else {
        fprintf(stdout, "attepmt to write to ROM %04x\n", address);
    }
}
