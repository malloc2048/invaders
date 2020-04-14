#include <cstdio>
#include "handlers.h"
#include "intel8080.h"

void Emulate8080(State8080* state) {
    uint8_t* opcode = &state->memory[state->pc];
    (*handlers[*opcode]) (state, opcode);
}

void Run(State8080* state, long bufferLength) {
    if(nullptr != state) {
        while (state->pc < bufferLength) {
#if DEBUG_ON == 1
            printf("address 0x%04x => %02x: ", state->pc, state->memory[state->pc]);
#endif
            Emulate8080(state);
        }
    }
}
