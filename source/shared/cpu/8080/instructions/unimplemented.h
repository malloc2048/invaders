#ifndef EMULATOR_UNIMPLEMENTED_H
#define EMULATOR_UNIMPLEMENTED_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void UnimplementedInstruction(State8080* state, const uint8_t* opcode) {
    printf("error: unimplemented instruction 0x%02x\n", *opcode);
//    exit(1);
}
#endif
