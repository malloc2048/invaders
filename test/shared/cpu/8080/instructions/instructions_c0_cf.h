#ifndef EMULATOR_INSTRUCTIONS_C0_CF_H
#define EMULATOR_INSTRUCTIONS_C0_CF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RNZ(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RNZ\n");
#endif
    state->pc += 1;
}

void PopB(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("Pop B\n");
#endif
    state->pc += 1;
}

void JNZ(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("JNZ\n");
#endif
    state->pc += 1;
}

void JMP(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("JMP\n");
#endif
    state->pc += 1;
}

void CNZ(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CNZ\n");
#endif
    state->pc += 1;
}

void PushB(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("PUSH B\n");
#endif
    state->pc += 1;
}

void ADI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ADI\n");
#endif
    state->pc += 1;
}

void RST0(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RST0\n");
#endif
    state->pc += 1;
}

void RZ(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RZ\n");
#endif
    state->pc += 1;
}

void RET(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RET\n");
#endif
    state->pc += 1;
}

void JZ(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("JZ\n");
#endif
    state->pc += 1;
}

void CZ(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CZ\n");
#endif
    state->pc += 1;
}

void CALL(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("CALL\n");
#endif
    state->pc += 1;
}

void ACI(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("ACI\n");
#endif
    state->pc += 1;
}

void RST1(State8080 *state, const uint8_t *opcode) {
#if TRACE_ON == 1
    printf("RST1\n");
#endif
    state->pc += 1;
}

#endif
