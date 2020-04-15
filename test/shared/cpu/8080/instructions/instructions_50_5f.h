#ifndef EMULATOR_INSTRUCTIONS_50_5F_H
#define EMULATOR_INSTRUCTIONS_50_5F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_D_B(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, B\n");
#endif
    state->pc += 1;
}

void MOV_D_C(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, C\n");
#endif
    state->pc += 1;
}

void MOV_D_D(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, D\n");
#endif
    state->pc += 1;
}

void MOV_D_E(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, E\n");
#endif
    state->pc += 1;
}

void MOV_D_H(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, H\n");
#endif
    state->pc += 1;
}

void MOV_D_L(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, L\n");
#endif
    state->pc += 1;
}

void MOV_D_M(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, M\n");
#endif
    state->pc += 1;
}

void MOV_D_A(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV D, A\n");
#endif
    state->pc += 1;
}

void MOV_E_B(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, B\n");
#endif
    state->pc += 1;
}

void MOV_E_C(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, C\n");
#endif
    state->pc += 1;
}

void MOV_E_D(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, D\n");
#endif
    state->pc += 1;
}

void MOV_E_E(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, E\n");
#endif
    state->pc += 1;
}

void MOV_E_H(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, H\n");
#endif
    state->pc += 1;
}

void MOV_E_L(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, L\n");
#endif
    state->pc += 1;
}

void MOV_E_M(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, M\n");
#endif
    state->pc += 1;
}

void MOV_E_A(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV E, A\n");
#endif
    state->pc += 1;
}

#endif
