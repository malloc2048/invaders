#include "cpu/8080/instructions/data_transfer_group.h"

void NoOp(State8080 *state) {
    if(TraceOn())
        fprintf(TraceOut(), "NOP\n");
    state->pc += 1;
}

void LoadRegisterPairImmediateSP(State8080* state) {
    uint16_t address = (state->memory[state->pc + 2] << 8) | state->memory[state->pc + 1];
    state->sp = address;
    state->pc += 3;

    if(TraceOn())
        fprintf(TraceOut(), "LXI SP %04x\n", address);
}

void LoadRegisterPairImmediateDE(State8080* state) {
    state->d = state->memory[state->pc + 2];
    state->e = state->memory[state->pc + 1];
    state->pc += 3;

    if(TraceOn())
        fprintf(TraceOut(), "LXI DE %02x%02x\n", state->d, state->e);
}

void LoadRegisterPairImmediateHL(State8080* state) {
    state->h = state->memory[state->pc + 2];
    state->l = state->memory[state->pc + 1];
    state->pc += 3;

    if(TraceOn())
        fprintf(TraceOut(), "LXI HL %02x%02x\n", state->h, state->l);
}

void LoadAccumulatorIndirectBC(State8080* state) {
    uint16_t address = (state->b << 8) | state->c;
    state->a = state->memory[address];

    if(TraceOn())
        fprintf(TraceOut(), "LDAX BC %02x\n", state->a);

    state->pc += 1;
}

void LoadAccumulatorIndirectDE(State8080* state) {
    uint16_t address = (state->d << 8) | state->e;
    state->a = state->memory[address];

    if(TraceOn())
        fprintf(TraceOut(), "LDAX DE %02x\n", state->a);

    state->pc += 1;
}