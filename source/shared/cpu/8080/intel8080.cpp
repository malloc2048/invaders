#include <cstdio>
#include "cpu/8080/intel8080.h"
#include "cpu/8080/instruction_functions.h"

void Emulate8080(State8080* state, long bufferLength) {
    if(nullptr != state) {
        while (state->pc < bufferLength) {
            uint8_t currentOpCode = state->memory[state->pc];
            if(TraceOn())
                fprintf(TraceOut(), "0x%04x\t%02x\t", state->pc, state->memory[state->pc]);
//            uint8_t *opcode = &state->memory[state->pc];
//            (*handlers[*opcode])(state, opcode);

            (*handlers[state->memory[state->pc]])(state);
        }
    }
}
