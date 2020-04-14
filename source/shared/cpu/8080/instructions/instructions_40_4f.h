#ifndef EMULATOR_INSTRUCTIONS_40_4F_H
#define EMULATOR_INSTRUCTIONS_40_4F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_B_B(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, B\n");
#endif
    state->pc += 1;
}

void MOV_B_C(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, C\n");
#endif
    state->pc += 2;
}

void MOV_B_D(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, D\n");
#endif
    state->pc += 1;
}

void MOV_B_E(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, E\n");
#endif
    state->pc += 1;
}

void MOV_B_H(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, H\n");
#endif
    state->pc += 1;
}

void MOV_B_L(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, L\n");
#endif
    state->pc += 1;
}

void MOV_B_M(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, M\n");
#endif
    state->pc += 1;
}

void MOV_B_A(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV B, A\n");
#endif
    state->pc += 1;
}

void MOV_C_B(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, B\n");
#endif
    state->pc += 1;
}

void MOV_C_C(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, C\n");
#endif
    state->pc += 1;
}

void MOV_C_D(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, D\n");
#endif
    state->pc += 1;
}

void MOV_C_E(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, E\n");
#endif
    state->pc += 1;
}

void MOV_C_H(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, H\n");
#endif
    state->pc += 1;
}

void MOV_C_L(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, L\n");
#endif
    state->pc += 1;
}

void MOV_C_M(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, M\n");
#endif
    state->pc += 1;
}

void MOV_C_A(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MOV C, A\n");
#endif
    state->pc += 1;
}

#endif
