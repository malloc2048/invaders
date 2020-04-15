#include <cpu/8080/state.h>
#include "cpu/8080/instructions/arithmetic_group.h"

void DecrementRegisterB(State8080* state) {
    state->b -= 1;

    if(TraceOn())
        fprintf(TraceOut(), "DCR B %02x\n", state->b);
    state->pc += 1;
}

void AddRegisterPairDE(State8080* state) {
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

    if(TraceOut())
        fprintf(TraceOut(), "DAD H %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}

void AddRegisterPairHL(State8080* state) {
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

    if(TraceOut())
        fprintf(TraceOut(), "DAD H %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}
