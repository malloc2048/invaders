#include "cpu/8080/instructions/arithmetic_group.h"

void INX_D(State8080* state) {
    if(state->e == 0xff)
        state->d += 1;
    state->e += 1;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "INX DE %02x%02x\n", state->d, state->e);
}

void INX_H(State8080* state) {
    if(state->l == 0xff)
        state->h += 1;
    state->l += 1;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "INX HL %02x%02x\n", state->h, state->l);
}
