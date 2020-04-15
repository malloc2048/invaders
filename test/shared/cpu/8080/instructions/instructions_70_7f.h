#ifndef EMULATOR_INSTRUCTIONS_70_7F_H
#define EMULATOR_INSTRUCTIONS_70_7F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_M_B(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV M, B\n");
#endif
    state->pc += 1;
}

void MOV_M_C(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV M, C\n");
#endif
    state->pc += 1;
}

void MOV_M_D(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV M, D\n");
#endif
    state->pc += 1;
}

void MOV_M_E(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV M, E\n");
#endif
    state->pc += 1;
}

void MOV_M_H(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV M, H\n");
#endif
    state->pc += 1;
}

void MOV_M_L(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV M, L\n");
#endif
    state->pc += 1;
}

void HLT(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("HLT\n");
#endif
    state->pc += 1;
}

void MOV_M_A(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV M, A\n");
#endif
    state->pc += 1;
}

void MOV_A_B(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, B\n");
#endif
    state->pc += 1;
}

void MOV_A_C(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, C\n");
#endif
    state->pc += 1;
}

void MOV_A_D(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, D\n");
#endif
    state->pc += 1;
}

void MOV_A_E(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, E\n");
#endif
    state->pc += 1;
}

void MOV_A_H(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, H\n");
#endif
    state->pc += 1;
}

void MOV_A_L(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, L\n");
#endif
    state->pc += 1;
}

void MOV_A_M(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, M\n");
#endif
    state->pc += 1;
}

void MOV_A_A(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV A, A\n");
#endif
    state->pc += 1;
}

#endif
