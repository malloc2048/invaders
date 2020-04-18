#ifndef EMULATOR_UTILITIES_H
#define EMULATOR_UTILITIES_H

#include <cstdio>
#include <cstdint>

namespace utilities {
    void swap(uint8_t& x, uint8_t& y);
}

long GetFileSize(FILE* file);
uint8_t Parity(uint32_t number, uint8_t size);
uint8_t* ReadFile(FILE* file, long fileLength);
long ReadRomFile(FILE* file, uint8_t* buffer);
#endif
