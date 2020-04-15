#ifndef EMULATOR_INSTRUCTIONS_E0_EF_H
#define EMULATOR_INSTRUCTIONS_E0_EF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RPO(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RPO\n");
#endif
    state->pc += 1;
}

void POPH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("POP H\n");
#endif
    state->pc += 1;
}

void JPO(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("JPO\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void XTHL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XTHL\n");
#endif
    state->pc += 1;
}

void CPO(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CPO\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void PUSHH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("PUSH H\n");
#endif
    state->pc += 1;
}

void ANI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANI\n");
#endif
    state->pc += 1;
    state->pc += 1;
}

void RST4(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RST 4\n");
#endif
    state->pc += 1;
}

void RPE(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RPE\n");
#endif
    state->pc += 1;
}

void PCHL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("PCHL\n");
#endif
    state->pc += 1;
}

void JPE(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("JPE\n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void XCHG(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XCHG\n");
#endif
    state->pc += 1;
}

void CPE(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CPE \n");
#endif
    state->pc += 2;
    state->pc += 1;
}

void XRI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRI\n");
#endif
    state->pc += 1;
    state->pc += 1;
}

void RST5(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RST5\n");
#endif
    state->pc += 1;
}

#endif
