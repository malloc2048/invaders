#ifndef EMULATOR_INSTRUCTIONS_D0_DF_H
#define EMULATOR_INSTRUCTIONS_D0_DF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RNC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RNC \n");
#endif
    state->pc += 1;
}

void POPD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("POP D \n");
#endif
    state->pc += 1;
}

void JNC(State8080 *state, const uint8_t *opcode) {
    state->pc += 2;
#if DEBUG_ON == 1
    printf("JNC \n");
#endif
    state->pc += 1;
}

void OUT(State8080 *state, const uint8_t *opcode) {
    state->pc += 1;
#if DEBUG_ON == 1
    printf("OUT \n");
#endif
    state->pc += 1;
}

void CNC(State8080 *state, const uint8_t *opcode) {
    state->pc += 2;
#if DEBUG_ON == 1
    printf("CNC \n");
#endif
    state->pc += 1;
}

void PushD(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("PUSH D\n");
#endif
    state->pc += 1;
}

void SUI(State8080 *state, const uint8_t *opcode) {
    state->pc += 1;
#if DEBUG_ON == 1
    printf("SUI \n");
#endif
    state->pc += 1;
}

void RST2(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RST 2 \n");
#endif
    state->pc += 1;
}

void RC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RC \n");
#endif
    state->pc += 1;
}

void JC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("JC\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void IN(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("IN D8\n");
#endif
    state->pc += 1;
    state->pc += 1;
}

void CC(State8080 *state, const uint8_t *opcode) {
    state->pc += 2;
#if DEBUG_ON == 1
    printf("CC \n");
#endif
    state->pc += 1;
}

void SBI(State8080 *state, const uint8_t *opcode) {
    state->pc += 1;
#if DEBUG_ON == 1
    printf("SBI \n");
#endif
    state->pc += 1;
}

void RST3(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RST3 \n");
#endif
    state->pc += 1;
}

#endif
