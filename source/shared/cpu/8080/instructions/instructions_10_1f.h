#ifndef EMULATOR_INSTRUCTIONS_10_1F_H
#define EMULATOR_INSTRUCTIONS_10_1F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void LXID(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("LXI D\n");
#endif
    state->c = opcode[1];
    state->b = opcode[2];
    state->pc += 3;
}

void STAXD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("STAX D\n");
#endif
    state->pc += 1;
}

void INXD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("INX D\n");
#endif
    state->pc += 1;
}

void INRD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("INR D\n");
#endif
    state->pc += 1;
}

void DCRD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DCR D\n");
#endif
    state->pc += 1;
}

void MVID(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MVI D\n");
#endif
    state->pc += 2;
}

void RAL(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RAL\n");
#endif
    state->pc += 1;
}

void DADD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DAD D\n");
#endif
    state->pc += 1;
}

void LDAXD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("LDAX D\n");
#endif
    state->pc += 1;
}

void DCXD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DCX D\n");
#endif
    state->pc += 1;
}

void INRE(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("INR E\n");
#endif
    state->pc += 1;
}

void DCRE(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DCR E\n");
#endif
    state->pc += 1;
}

void MVIE(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MVI E\n");
#endif
    state->pc += 2;
}

void RAR(struct State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RAR\n");
#endif
    state->pc += 1;
}

#endif
