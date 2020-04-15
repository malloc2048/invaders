#ifndef EMULATOR_INSTRUCTIONS_20_2F_H
#define EMULATOR_INSTRUCTIONS_20_2F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void LXIH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("LXI H\n");
#endif
    state->pc += 3;
}

void SHLD(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("SHLD\n");
#endif
    state->pc += 3;
}

void INXH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("INX H\n");
#endif
    state->pc += 3;
}

void INRH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("INR H\n");
#endif
    state->pc += 3;
}

void DCRH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DCR H\n");
#endif
    state->pc += 3;
}

void MVIH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MVI H\n");
#endif
    state->pc += 3;
}

void DAA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DAA\n");
#endif
    state->pc += 3;
}

void DADH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DAD H\n");
#endif
    state->pc += 3;
}

void LHLD(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("LHLD\n");
#endif
    state->pc += 3;
}

void DCXH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DCXH\n");
#endif
    state->pc += 3;
}

void INRL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("INR L\n");
#endif
    state->pc += 3;
}

void DCRL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DCR L\n");
#endif
    state->pc += 3;
}

void MVIL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MVI L\n");
#endif
    state->pc += 3;
}

void CMA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMA\n");
#endif
    state->pc += 3;
}

#endif
