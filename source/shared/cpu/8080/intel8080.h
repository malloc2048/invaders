#ifndef EMULATOR_INTEL8080_H
#define EMULATOR_INTEL8080_H

#include <cstdint>
#include "state.h"

void Emulate8080(State8080* state);
void Run(uint8_t* buffer, long bufferLength);
#endif
