#ifndef EMULATOR_INSTRUCTIONS_A0_AF_H
#define EMULATOR_INSTRUCTIONS_A0_AF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void ANAB(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA B\n");
#endif
    state->pc += 1;
}

void ANAC(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA C\n");
#endif
    state->pc += 1;
}

void ANAD(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA D\n");
#endif
    state->pc += 1;
}

void ANAE(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA E\n");
#endif
    state->pc += 1;
}

void ANAH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA H\n");
#endif
    state->pc += 1;
}

void ANAL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA L\n");
#endif
    state->pc += 1;
}

void ANAM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA M\n");
#endif
    state->pc += 1;
}

void ANAA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ANA A\n");
#endif
    state->pc += 1;
}

void XRAB(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA B\n");
#endif
    state->pc += 1;
}

void XRAC(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA C\n");
#endif
    state->pc += 1;
}

void XRAD(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA D\n");
#endif
    state->pc += 1;
}

void XRAE(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA E\n");
#endif
    state->pc += 1;
}

void XRAH(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA H\n");
#endif
    state->pc += 1;
}

void XRAL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA L\n");
#endif
    state->pc += 1;
}

void XRAM(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA M\n");
#endif
    state->pc += 1;
}

void XRAA(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("XRA A\n");
#endif
    state->pc += 1;
}

#endif
