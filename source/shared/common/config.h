#ifndef EMULATOR_CONFIG_H
#define EMULATOR_CONFIG_H

#include <cstdio>

#define LOGGING_LEVEL 3

void TraceOn();
void TraceOff();
int IsTraceOn();
FILE* TraceOut();

namespace config {
    int IsHexDump();
}

#endif
