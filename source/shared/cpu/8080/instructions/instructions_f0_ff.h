#ifndef EMULATOR_INSTRUCTIONS_F0_FF_H
#define EMULATOR_INSTRUCTIONS_F0_FF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RP(State8080* state, const uint8_t* opcode) {
    printf("RP\n");
    state->pc += 1;
}

void POP_PSW(State8080* state, const uint8_t* opcode) {
    printf("POP PSW\n");
    state->pc += 1;
}

void JP(State8080* state, const uint8_t* opcode) {
    printf("JP\n");
    state->pc += 2;
    state->pc += 1;
}

void DI(State8080* state, const uint8_t* opcode) {
    printf("DI\n");
    state->pc += 1;
}

void CP(State8080* state, const uint8_t* opcode) {
    printf("CP\n");
    state->pc += 2;
    state->pc += 1;
}

void PUSH_PSW(State8080* state, const uint8_t* opcode) {
    printf("PUSH PSW\n");
    state->pc += 1;
}

void ORI(State8080* state, const uint8_t* opcode) {
    printf("ORI\n");
    state->pc += 1;
    state->pc += 1;
}

void RST6(State8080* state, const uint8_t* opcode) {
    printf("RST 6\n");
    state->pc += 1;
}

void RM(State8080* state, const uint8_t* opcode) {
    printf("RM\n");
    state->pc += 1;
}

void SPHL(State8080* state, const uint8_t* opcode) {
    printf("SPHL\n");
    state->pc += 1;
}

void JM(State8080* state, const uint8_t* opcode) {
    printf("JM\n");
    state->pc += 2;
    state->pc += 1;
}

void EI(State8080* state, const uint8_t* opcode) {
    printf("EI\n");
    state->pc += 1;
}

void CM(State8080* state, const uint8_t* opcode) {
    printf("CM\n");
    state->pc += 2;
    state->pc += 1;
}

void CPI(State8080* state, const uint8_t* opcode) {
    printf("CPI\n");
    state->pc += 1;
    state->pc += 1;
}
void RST7(State8080* state, const uint8_t* opcode) {
    printf("RST 7\n");
    state->pc += 1;
}
#endif
