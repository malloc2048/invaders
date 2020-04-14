#ifndef EMULATOR_INSTRUCTIONS_90_9F_H
#define EMULATOR_INSTRUCTIONS_90_9F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void SUBB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB B\n");
#endif
    state->pc += 1;
}

void SUBC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB C\n");
#endif
    state->pc += 1;
}

void SUBD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB D\n");
#endif
    state->pc += 1;
}

void SUBE(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB E\n");
#endif
    state->pc += 1;
}

void SUBH(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB H\n");
#endif
    state->pc += 1;
}

void SUBL(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB L\n");
#endif
    state->pc += 1;
}

void SUBM(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB M\n");
#endif
    state->pc += 1;
}

void SUBA(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SUB A\n");
#endif
    state->pc += 1;
}

void SBBB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB B\n");
#endif
    state->pc += 1;
}

void SBBC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB C\n");
#endif
    state->pc += 1;
}

void SBBD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB D\n");
#endif
    state->pc += 1;
}

void SBBE(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB E\n");
#endif
    state->pc += 1;
}

void SBBH(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB H\n");
#endif
    state->pc += 1;
}

void SBBL(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB L\n");
#endif
    state->pc += 1;
}

void SBBM(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB M\n");
#endif
    state->pc += 1;
}

void SBBA(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("SBB A\n");
#endif
    state->pc += 1;
}

#endif
