#include "cpu/8080/instructions/arithmetic_group.h"

void DAD_B(State8080* state) {
    uint16_t low = state->c + state->l;
    state->l = low & 0xff;
    uint16_t high = state->b + state->h;
    state->h = high & 0xff;
    if((high & 0xff00) > 0) {
        state->cc.cy = 1;
    } else {
        state->cc.cy = 0;
    }
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "DAD BC %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}

void DAD_D(State8080* state) {
    uint16_t low = state->e + state->l;
    state->l = low & 0xff;
    uint16_t high = state->d + state->h;
    state->h = high & 0xff;
    if((high & 0xff00) > 0) {
        state->cc.cy = 1;
    } else {
        state->cc.cy = 0;
    }
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "DAD DE %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}

void DAD_H(State8080* state) {
    uint16_t low = state->l + state->l;
    state->l = low & 0xff;
    uint16_t high = state->h + state->h;
    state->h = high & 0xff;
    if((high & 0xff00) > 0) {
        state->cc.cy = 1;
    } else {
        state->cc.cy = 0;
    }
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "DAD HL %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}
