#ifndef EMULATOR_INTEL8080_H
#define EMULATOR_INTEL8080_H

#include <cstdint>
#include "state.h"

void Emulate8080(State8080* state, long bufferLength);
#endif
