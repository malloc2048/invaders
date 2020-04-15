#ifndef EMULATOR_INSTRUCTIONS_B0_BF_H
#define EMULATOR_INSTRUCTIONS_B0_BF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void ORAB(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA B\n");
#endif
    state->pc += 1;
}

void ORAC(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA C\n");
#endif
    state->pc += 1;
}

void ORAD(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA D\n");
#endif
    state->pc += 1;
}

void ORAE(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA E\n");
#endif
    state->pc += 1;
}

void ORAH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA H\n");
#endif
    state->pc += 1;
}

void ORAL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA L\n");
#endif
    state->pc += 1;
}

void ORAM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA M\n");
#endif
    state->pc += 1;
}

void ORAA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ORA A\n");
#endif
    state->pc += 1;
}

void CMPB(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP B\n");
#endif
    state->pc += 1;
}

void CMPC(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP C\n");
#endif
    state->pc += 1;
}

void CMPD(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP D\n");
#endif
    state->pc += 1;
}

void CMPE(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP E\n");
#endif
    state->pc += 1;
}

void CMPH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP H\n");
#endif
    state->pc += 1;
}

void CMPL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP L\n");
#endif
    state->pc += 1;
}

void CMPM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP M\n");
#endif
    state->pc += 1;
}

void CMPA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CMP A\n");
#endif
    state->pc += 1;
}

#endif
