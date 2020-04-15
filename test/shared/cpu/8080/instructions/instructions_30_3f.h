#ifndef EMULATOR_INSTRUCTIONS_30_3F_H
#define EMULATOR_INSTRUCTIONS_30_3F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void LXISP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("LXI SP\n");
#endif
    state->pc += 3;
}

void STA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("STA\n");
#endif
    state->pc += 3;
}

void INXSP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("INX SP\n");
#endif
    state->pc += 1;
}

void INRM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("INR M\n");
#endif
    state->pc += 1;
}

void DCRM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DCR M\n");
#endif
    state->pc += 1;
}

void MVIM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MVI M\n");
#endif
    state->pc += 2;
}

void STC(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("STC\n");
#endif
    state->pc += 1;
}

void DADSP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DAD SP\n");
#endif
    state->pc += 1;
}

void LDA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("LDA\n");
#endif
    state->pc += 3;
}

void DCXSP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DCX SP\n");
#endif
    state->pc += 1;
}

void INRA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("INR A\n");
#endif
    state->pc += 1;
}

void DCRA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DCR A\n");
#endif
    state->pc += 1;
}

void MVIA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MVI A\n");
#endif
    state->pc += 2;
}

void CMC(struct State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMC\n");
#endif
    state->pc += 1;
}

#endif
