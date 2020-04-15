#ifndef EMULATOR_CONFIG_H
#define EMULATOR_CONFIG_H

#include <cstdio>

#define LOGGING_LEVEL 3

int Emulate();
int TraceOn();
FILE* TraceOut();
#endif
