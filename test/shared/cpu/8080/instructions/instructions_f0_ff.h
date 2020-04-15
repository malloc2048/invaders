#ifndef EMULATOR_INSTRUCTIONS_F0_FF_H
#define EMULATOR_INSTRUCTIONS_F0_FF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RP\n");
#endif
    state->pc += 1;
}

void POP_PSW(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("POP PSW\n");
#endif
    state->pc += 1;
}

void JP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("JP\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void DI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("DI\n");
#endif
    state->pc += 1;
}

void CP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CP\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void PUSH_PSW(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("PUSH PSW\n");
#endif
    state->pc += 1;
}

void ORI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORI\n");
#endif
    state->pc += 1;
    state->pc += 1;
}

void RST6(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RST 6\n");
#endif
    state->pc += 1;
}

void RM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RM\n");
#endif
    state->pc += 1;
}

void SPHL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("SPHL\n");
#endif
    state->pc += 1;
}

void JM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("JM\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void EI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("EI\n");
#endif
    state->pc += 1;
}

void CM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CM\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void CPI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CPI\n");
#endif
    state->pc += 1;
    state->pc += 1;
}

void RST7(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RST 7\n");
#endif
    state->pc += 1;
}

#endif
