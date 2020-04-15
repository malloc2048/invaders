#ifndef EMULATOR_INSTRUCTIONS_60_6F_H
#define EMULATOR_INSTRUCTIONS_60_6F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_H_B(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, B\n");
#endif
    state->pc += 1;
    state->pc += 1;
}

void MOV_H_C(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, C\n");
#endif
    state->pc += 1;
}

void MOV_H_D(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, D\n");
#endif
    state->pc += 1;
}

void MOV_H_E(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, E\n");
#endif
    state->pc += 1;
}

void MOV_H_H(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, H\n");
#endif
    state->pc += 1;
}

void MOV_H_L(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, L\n");
#endif
    state->pc += 1;
}

void MOV_H_M(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, M\n");
#endif
    state->pc += 1;
}

void MOV_H_A(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV H, A\n");
#endif
    state->pc += 1;
}

void MOV_L_B(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, B\n");
#endif
    state->pc += 1;
}

void MOV_L_C(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, C\n");
#endif
    state->pc += 1;
}

void MOV_L_D(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, D\n");
#endif
    state->pc += 1;
}

void MOV_L_E(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, E\n");
#endif
    state->pc += 1;
}

void MOV_L_H(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, H\n");
#endif
    state->pc += 1;
}

void MOV_L_L(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, L\n");
#endif
    state->pc += 1;
}

void MOV_L_M(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, M\n");
#endif
    state->pc += 1;
}

void MOV_L_A(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("MOV L, A\n");
#endif
    state->pc += 1;
}

#endif
