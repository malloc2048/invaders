#include <cstdio>
#include "cpu/8080/intel8080.h"
#include "cpu/8080/instruction_functions.h"

void Run(State8080* state, long bufferLength) {
    if(nullptr != state) {
        while (state->pc < bufferLength) {
            Emulate8080(state);
        }
    }
}

void Emulate8080(State8080* state) {
//    uint8_t currentOpCode = state->memory[state->pc];
    if(IsTraceOn())
        fprintf(TraceOut(), "0x%04x\t%02x\t", state->pc, state->memory[state->pc]);

    (*handlers[state->memory[state->pc]])(state);
}
