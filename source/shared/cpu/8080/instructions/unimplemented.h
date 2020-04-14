#ifndef EMULATOR_UNIMPLEMENTED_H
#define EMULATOR_UNIMPLEMENTED_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void UnimplementedInstruction(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("error: unimplemented instruction 0x%02x\n", *opcode);
#endif
    state->pc += 1;
//    exit(1);
}
#endif
