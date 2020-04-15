#include "cpu/8080/instructions/arithmetic_group.h"

void IncrementRegisterPairDE(State8080* state) {
    uint16_t value = (((state->d & 0xff) << 8) | state->e) + 1;
    state->d = (value & 0xff00) >> 8;
    state->e = value & 0xff;

    if(TraceOn())
        fprintf(TraceOut(), "INX DE %02x%02x\n", state->d, state->e);
    state->pc += 1;
}

void IncrementRegisterPairHL(State8080* state) {
    uint16_t value = (((state->h & 0xff) << 8) | state->l) + 1;
    state->h = (value & 0xff00) >> 8;
    state->l = value & 0xff;

    if(TraceOn())
        fprintf(TraceOut(), "INX HL %02x%02x\n", state->h, state->l);
    state->pc += 1;
}
