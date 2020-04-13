#ifndef EMULATOR_INSTRUCTIONS_D0_DF_H
#define EMULATOR_INSTRUCTIONS_D0_DF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RNC(State8080* state, const uint8_t* opcode) {
    printf("RNC \n");
}

void POPD(State8080* state, const uint8_t* opcode) {
    printf("POP D \n");
}

void JNC(State8080* state, const uint8_t* opcode) {
    state->pc += 2;
    printf("JNC \n");
}

void OUT(State8080* state, const uint8_t* opcode) {
    state->pc += 1;
    printf("OUT \n");
}

void CNC(State8080* state, const uint8_t* opcode) {
    state->pc += 2;
    printf("CNC \n");
}

void PushD(State8080* state, const uint8_t* opcode) {
    printf("PUSH D\n");
}

void SUI(State8080* state, const uint8_t* opcode) {
    state->pc += 1;
    printf("SUI \n");
}

void RST2(State8080* state, const uint8_t* opcode) {
    printf("RST 2 \n");
}

void RC(State8080* state, const uint8_t* opcode) {
    printf("RC \n");
}

void JC(State8080* state, const uint8_t* opcode) {
    printf("JC\n");
    state->pc += 2;
}

void IN(State8080* state, const uint8_t* opcode) {
    printf("IN D8\n");
    state->pc += 1;
}

void CC(State8080* state, const uint8_t* opcode) {
    state->pc += 2;
    printf("CC \n");
}

void SBI(State8080* state, const uint8_t* opcode) {
    state->pc += 1;
    printf("SBI \n");
}

void RST3(State8080* state, const uint8_t* opcode) {
    printf("RST3 \n");
}
#endif
