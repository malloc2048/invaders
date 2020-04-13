#ifndef EMULATOR_INSTRUCTIONS_F0_FF_H
#define EMULATOR_INSTRUCTIONS_F0_FF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RP(State8080* state, const uint8_t* opcode) {
    printf("RP\n");
}

void POP_PSW(State8080* state, const uint8_t* opcode) {
    printf("POP PSW\n");
}

void JP(State8080* state, const uint8_t* opcode) {
    printf("JP\n");
    state->pc += 2;
}

void DI(State8080* state, const uint8_t* opcode) {
    printf("DI\n");
}

void CP(State8080* state, const uint8_t* opcode) {
    printf("CP\n");
    state->pc += 2;
}

void PUSH_PSW(State8080* state, const uint8_t* opcode) {
    printf("PUSH PSW\n");
}

void ORI(State8080* state, const uint8_t* opcode) {
    printf("ORI\n");
    state->pc += 1;
}

void RST6(State8080* state, const uint8_t* opcode) {
    printf("RST 6\n");
}

void RM(State8080* state, const uint8_t* opcode) {
    printf("RM\n");
}

void SPHL(State8080* state, const uint8_t* opcode) {
    printf("SPHL\n");
}

void JM(State8080* state, const uint8_t* opcode) {
    printf("JM\n");
    state->pc += 2;
}

void EI(State8080* state, const uint8_t* opcode) {
    printf("EI\n");
}

void CM(State8080* state, const uint8_t* opcode) {
    printf("CM\n");
    state->pc += 2;
}

void CPI(State8080* state, const uint8_t* opcode) {
    printf("CPI\n");
    state->pc += 1;
}
void RST7(State8080* state, const uint8_t* opcode) {
    printf("RST 7\n");
}
#endif
