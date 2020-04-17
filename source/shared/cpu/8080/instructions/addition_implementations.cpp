#include "cpu/8080/instructions/arithmetic_group.h"

void DAD_B(State8080* state) {
    uint16_t lowByte = state->c + state->l;
    uint16_t highByte = state->b + state->h + ((lowByte & 0xff00u) >> 8u);

    state->l = lowByte & 0xffu;
    state->h = highByte & 0xffu;
    state->cc.cy = (highByte & 0xff00u) >> 8u;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "DAD B %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}

void DAD_D(State8080* state) {
    uint16_t lowByte = state->e + state->l;
    uint16_t highByte = state->d + state->h + ((lowByte & 0xff00u) >> 8u);

    state->l = lowByte & 0xffu;
    state->h = highByte & 0xffu;
    state->cc.cy = (highByte & 0xff00u) >> 8u;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "DAD D %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}

void DAD_H(State8080* state) {
    uint16_t lowByte = state->l + state->l;
    uint16_t highByte = state->h + state->h + ((lowByte & 0xff00u) >> 8u);

    state->l = lowByte & 0xffu;
    state->h = highByte & 0xffu;
    state->cc.cy = (highByte & 0xff00u) >> 8u;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "DAD D %02x%02x %02x\n", state->h, state->l, state->cc.cy);
}
