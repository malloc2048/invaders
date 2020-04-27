#include "ram.h"
#include <iomanip>
#include <iostream>

uint8_t RAM::read(uint16_t address) const {
    return ram[address];
}

bool RAM::write(uint16_t address, uint8_t value) {
    if(writeProtected && address < ROM_MAX_ADDR) {
        std::cout << std::setw(4) << std::hex << std::setfill('0');
        std::cout << "attempt to write to ROM address 0x" << address << std::endl;
        return false;
    }

    ram[address] = value;
    return true;
}

void RAM::loadRom() {
    writeProtected = false;
}

void RAM::lockRom() {
    writeProtected = true;
}

void RAM::loadRom(FILE* romFile) {
    fseek(romFile, 0L, SEEK_END);
    auto fileLength = ftell(romFile);
    fseek(romFile, 0L, SEEK_SET);
    fread(ram + ROM_MIN_ADDR, sizeof(char), fileLength, romFile);
}
