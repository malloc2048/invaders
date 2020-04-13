#include <cstdio>
#include "handlers.h"
#include "intel8080.h"

void Emulate8080(State8080* state) {
    uint8_t* opcode = &state->memory[state->pc];
    (*handlers[*opcode]) (state, opcode);
//    state->pc += 1;
}

void Run(uint8_t* buffer, long bufferLength) {
    State8080 state;
    state.a = 0;
    state.b = 0;
    state.c = 0;
    state.d = 0;
    state.e = 0;
    state.h = 0;
    state.l = 0;
    state.sp = 0;
    state.pc = 0;
    state.memory = buffer;
    state.int_enable = 0;

    for(; state.pc < bufferLength; state.pc++) {
        printf("address 0x%04x => %02x: ", state.pc, state.memory[state.pc]);
        Emulate8080(&state);
    }
}
