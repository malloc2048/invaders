#ifndef EMULATOR_INSTRUCTIONS_C0_CF_H
#define EMULATOR_INSTRUCTIONS_C0_CF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RNZ(State8080* state, const uint8_t* opcode) {
    printf("RNZ\n");
    state->pc += 1;
}

void PopB(State8080* state, const uint8_t* opcode) {
    printf("Pop B\n");
    state->pc += 1;
}

void JNZ(State8080* state, const uint8_t* opcode) {
    printf("JNZ\n");
    state->pc += 1;
}

void JMP(State8080* state, const uint8_t* opcode) {
    printf("JMP\n");
    state->pc += 1;
}

void CNZ(State8080* state, const uint8_t* opcode) {
    printf("CNZ\n");
    state->pc += 1;
}

void PushB(State8080* state, const uint8_t* opcode) {
    printf("PUSH B\n");
    state->pc += 1;
}

void ADI(State8080* state, const uint8_t* opcode) {
    printf("ADI\n");
    state->pc += 1;
}

void RST0(State8080* state, const uint8_t* opcode) {
    printf("RST0\n");
    state->pc += 1;
}

void RZ(State8080* state, const uint8_t* opcode) {
    printf("RZ\n");
    state->pc += 1;
}

void RET(State8080* state, const uint8_t* opcode) {
    printf("RET\n");
    state->pc += 1;
}

void JZ(State8080* state, const uint8_t* opcode) {
    printf("JZ\n");
    state->pc += 1;
}

void CZ(State8080* state, const uint8_t* opcode) {
    printf("CZ\n");
    state->pc += 1;
}

void CALL(State8080* state, const uint8_t* opcode) {
    printf("CALL\n");
    state->pc += 1;
}

void ACI(State8080* state, const uint8_t* opcode) {
    printf("ACI\n");
    state->pc += 1;
}

void RST1(State8080* state, const uint8_t* opcode) {
    printf("RST1\n");
    state->pc += 1;
}
#endif
