#ifndef EMULATOR_UTILITIES_H
#define EMULATOR_UTILITIES_H

#include <cstdio>
#include <cstdint>

long GetFileSize(FILE* file);
int Parity(int number, int size);
uint8_t* ReadFile(FILE* file, long fileLength);
#endif
