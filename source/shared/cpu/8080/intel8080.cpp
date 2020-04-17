#include <cstdio>
#include "cpu/8080/intel8080.h"
#include "cpu/8080/instruction_functions.h"

void Intel8080::Emulate8080() {
//    uint8_t currentOpCode = state->memory[state->pc];
    if(IsTraceOn())
        fprintf(TraceOut(), "0x%04x\t%02x\t", state.pc, state.memory[state.pc]);

    (*handlers[state.memory[state.pc]])(&state);
}

//void Intel8080::Run(State8080* _state, long bufferLength) {
void Intel8080::Run(long bufferLength) {
    while (state.pc < bufferLength) {
        Emulate8080();
    }
}
