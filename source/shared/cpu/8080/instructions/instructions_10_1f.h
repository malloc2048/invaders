#ifndef EMULATOR_INSTRUCTIONS_10_1F_H
#define EMULATOR_INSTRUCTIONS_10_1F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void LXID(State8080* state, const uint8_t* opcode) {
    printf("LXI D\n");
    state->c = opcode[1];
    state->b = opcode[2];
    state->pc += 3;
}

void STAXD(State8080* state, const uint8_t* opcode) {
    printf("STAX D\n");
    state->pc += 1;
}

void INXD(State8080* state, const uint8_t* opcode) {
    printf("INX D\n");
    state->pc += 1;
}

void INRD(State8080* state, const uint8_t* opcode) {
    printf("INR D\n");
    state->pc += 1;
}

void DCRD(State8080* state, const uint8_t* opcode) {
    printf("DCR D\n");
    state->pc += 1;
}

void MVID(State8080* state, const uint8_t* opcode) {
    printf("MVI D\n");
    state->pc += 2;
}

void RAL(State8080* state, const uint8_t* opcode) {
    printf("RAL\n");
    state->pc += 1;
}

void DADD(State8080* state, const uint8_t* opcode) {
    printf("DAD D\n");
    state->pc += 1;
}

void LDAXD(State8080* state, const uint8_t* opcode) {
    printf("LDAX D\n");
    state->pc += 1;
}

void DCXD(State8080* state, const uint8_t* opcode) {
    printf("DCX D\n");
    state->pc += 1;
}

void INRE(State8080* state, const uint8_t* opcode) {
    printf("INR E\n");
    state->pc += 1;
}

void DCRE(State8080* state, const uint8_t* opcode) {
    printf("DCR E\n");
    state->pc += 1;
}

void MVIE(State8080* state, const uint8_t* opcode) {
    printf("MVI E\n");
    state->pc += 2;
}

void RAR(struct State8080* state, const uint8_t* opcode) {
    printf("RAR\n");
    state->pc += 1;
}
#endif
