#ifndef EMULATOR_UTILITIES_H
#define EMULATOR_UTILITIES_H

#include <cstdio>
#include <cstdint>

long GetFileSize(FILE* file);
uint8_t* ReadFile(FILE* file, long fileLength);
#endif
