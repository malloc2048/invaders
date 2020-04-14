#ifndef EMULATOR_INSTRUCTIONS_00_0F_H
#define EMULATOR_INSTRUCTIONS_00_0F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void NOP(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("NOP\n");
#endif
    state->pc += 1;
}

void LXIB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("LXI B\n");
#endif
    state->c = opcode[1];
    state->b = opcode[2];
    state->pc += 3;
}

void STAXB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("STAX B\n");
#endif
    state->pc += 1;
}

void INXB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("INX B\n");
#endif
    state->pc += 1;
}

void INRB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("INR B\n");
#endif
    state->pc += 1;
}

void DCRB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DCR B\n");
#endif
    state->pc += 1;
}

void MVIB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MVI B\n");
#endif
    state->pc += 2;
}

void RLC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RLC\n");
#endif
    state->pc += 1;
}

void DADB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DAD B\n");
#endif
    state->pc += 1;
}

void LDAXB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("LDAX B\n");
#endif
    state->pc += 1;
}

void DCXB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DCX B\n");
#endif
    state->pc += 1;
}

void INRC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("INR C\n");
#endif
    state->pc += 1;
}

void DCRC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("DCR C\n");
#endif
    state->pc += 1;
}

void MVIC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("MVI C\n");
#endif
    state->pc += 2;
}

void RRC(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("RRC\n");
#endif
    state->pc += 1;
}

#endif
