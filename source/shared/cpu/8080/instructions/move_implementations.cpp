#include "cpu/8080/instructions/data_transfer_group.h"

// MVI B, data B <- (byte 2)
void MVI_B(State8080* state) {
    state->b = state->memory[state->pc + 1];

    if(IsTraceOn())
        fprintf(TraceOut(), "MVI B %02x\n", state->memory[state->pc + 1]);
    state->pc += 2;
}

// MVI C, data C <- (byte 2)
void MVI_C(State8080* state) {
    state->c = state->memory[state->pc + 1];

    if(IsTraceOn())
        fprintf(TraceOut(), "MVI C %02x\n", state->memory[state->pc + 1]);
    state->pc += 2;
}

// MVI H, data H <- byte 2
void MVI_H(State8080* state) {
    state->h = state->memory[state->pc + 1];
    state->pc += 2;

    if(IsTraceOn())
        fprintf(TraceOut(), "MVI H %02x\n", state->h);
}

// MVI M, data ((H))(L)) <- (byte 2)
void MVI_M(State8080* state) {
    uint16_t address = (state->h << 8) | state->l;
    state->memory[address] = state->memory[state->pc + 1];

    if(IsTraceOn())
        fprintf(TraceOut(), "MVI M %02x\n", state->memory[state->pc + 1]);
    state->pc += 2;
}

void MOV_M_A(State8080* state) {
    uint16_t address = (state->h << 8) | state->l;
    state->memory[address] = state->a;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "MOV HL, A %02x\n", state->memory[address]);
}

void MOV_H_A(State8080* state) {
    state->a = state->h;

    if(IsTraceOn())
        fprintf(TraceOut(), "MOV A, H %02x\n", state->a);
    state->pc += 1;
}

void MOV_L_A(State8080* state) {
    state->l = state->a;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "MOV L, A %02x\n", state->l);
}
