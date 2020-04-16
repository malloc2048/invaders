#include "cpu/8080/instructions/data_transfer_group.h"

void LXI_SP(State8080* state) {
    uint16_t address = (state->memory[state->pc + 2] << 8) | state->memory[state->pc + 1];
    state->sp = address;
    state->pc += 3;

    if(IsTraceOn())
        fprintf(TraceOut(), "LXI SP %04x\n", address);
}

void LXI_B(State8080* state) {
    state->b = state->memory[state->pc + 2];
    state->c = state->memory[state->pc + 1];
    state->pc += 3;

    if(IsTraceOn())
        fprintf(TraceOut(), "LXI BC %02x%02x\n", state->b, state->c);
}

void LXI_D(State8080* state) {
    state->d = state->memory[state->pc + 2];
    state->e = state->memory[state->pc + 1];
    state->pc += 3;

    if(IsTraceOn())
        fprintf(TraceOut(), "LXI DE %02x%02x\n", state->d, state->e);
}

void LXI_H(State8080* state) {
    state->h = state->memory[state->pc + 2];
    state->l = state->memory[state->pc + 1];
    state->pc += 3;

    if(IsTraceOn())
        fprintf(TraceOut(), "LXI HL %02x%02x\n", state->h, state->l);
}

void LDA(State8080* state) {
    uint16_t address = (state->memory[state->pc + 2] << 8) | state->memory[state->pc + 1];
    state->a = state->memory[address];
    state->pc += 2;

    if(IsTraceOn())
        fprintf(TraceOut(), "LDA %02x\n", state->a);
}

void LDAX_B(State8080* state) {
    uint16_t address = (state->b << 8) | state->c;
    state->a = state->memory[address];

    if(IsTraceOn())
        fprintf(TraceOut(), "LDAX BC %02x\n", state->a);

    state->pc += 1;
}

void LDAX_D(State8080* state) {
    uint16_t address = (state->d << 8) | state->e;
    state->a = state->memory[address];

    if(IsTraceOn())
        fprintf(TraceOut(), "LDAX DE %02x\n", state->a);

    state->pc += 1;
}

// XCHG (H) <-> (D) (L) <-> (E)
void XCHG(State8080* state) {
    uint8_t d = state->d;
    state->d = state->h;
    state->h = d;

    uint8_t e = state->e;
    state->e = state->l;
    state->l = e;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "XCHG HL DE %02x%02x %02x%02x\n", state->h, state->l, state->d, state->e);
}
