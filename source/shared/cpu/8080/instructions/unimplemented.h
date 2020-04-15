#ifndef EMULATOR_UNIMPLEMENTED_H
#define EMULATOR_UNIMPLEMENTED_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

//void UnimplementedInstruction(State8080 *state, const uint8_t *opcode) {
void UnimplementedInstruction(State8080 *state) {
    if(TraceOn())
        fprintf(TraceOut(), "unimplemented instruction 0x%02x\n", state->memory[state->pc]);
    exit(1);
}
#endif
