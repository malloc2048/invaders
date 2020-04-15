#include "cpu/8080/instructions/data_transfer_group.h"

// MVI B, data B <- (byte 2)
void MoveImmediateB(State8080* state) {
    state->b = state->memory[state->pc + 1];

    if(TraceOn())
        fprintf(TraceOut(), "MVI B %02x\n", state->memory[state->pc + 1]);
    state->pc += 2;
}

// MVI C, data C <- (byte 2)
void MoveImmediateC(State8080* state) {
    state->c = state->memory[state->pc + 1];

    if(TraceOn())
        fprintf(TraceOut(), "MVI C %02x\n", state->memory[state->pc + 1]);
    state->pc += 2;
}

// MVI H, data H <- byte 2
void MoveImmediateH(State8080* state) {
    state->h = state->memory[state->pc + 1];
    state->pc += 2;

    if(TraceOn())
        fprintf(TraceOut(), "MVI H %02x\n", state->h);
}

// MVI M, data ((H))(L)) <- (byte 2)
void MoveImmediateM(State8080* state) {
    uint16_t address = (state->h << 8) | state->l;
    state->memory[address] = state->memory[state->pc + 1];

    if(TraceOn())
        fprintf(TraceOut(), "MVI M %02x\n", state->memory[state->pc + 1]);
    state->pc += 2;
}

void MoveAccumulatorToMemoryHL(State8080* state) {
    uint16_t address = (state->h << 8) | state->l;
    state->memory[address] = state->a;
    state->pc += 1;

    if(TraceOn())
        fprintf(TraceOut(), "MOV HL, A %02x\n", state->memory[address]);
}

void MoveRegistersHA(State8080* state) {
    state->a = state->h;

    if(TraceOn())
        fprintf(TraceOut(), "MOV A, H %02x\n", state->a);
    state->pc += 1;
}

void MoveRegistersLA(State8080* state) {
    state->l = state->a;
    state->pc += 1;

    if(TraceOn())
        fprintf(TraceOut(), "MOV L, A %02x\n", state->l);
}
