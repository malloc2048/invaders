#ifndef EMULATOR_INSTRUCTIONS_50_5F_H
#define EMULATOR_INSTRUCTIONS_50_5F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_D_B(State8080* state, const uint8_t* opcode) {
    printf("MOV D, B\n");
    state->pc += 1;
}

void MOV_D_C(State8080* state, const uint8_t* opcode) {
    printf("MOV D, C\n");
    state->pc += 1;
}

void MOV_D_D(State8080* state, const uint8_t* opcode) {
    printf("MOV D, D\n");
    state->pc += 1;
}

void MOV_D_E(State8080* state, const uint8_t* opcode) {
    printf("MOV D, E\n");
    state->pc += 1;
}

void MOV_D_H(State8080* state, const uint8_t* opcode) {
    printf("MOV D, H\n");
    state->pc += 1;
}

void MOV_D_L(State8080* state, const uint8_t* opcode) {
    printf("MOV D, L\n");
    state->pc += 1;
}

void MOV_D_M(State8080* state, const uint8_t* opcode) {
    printf("MOV D, M\n");
    state->pc += 1;
}

void MOV_D_A(State8080* state, const uint8_t* opcode) {
    printf("MOV D, A\n");
    state->pc += 1;
}

void MOV_E_B(State8080* state, const uint8_t* opcode) {
    printf("MOV E, B\n");
    state->pc += 1;
}

void MOV_E_C(State8080* state, const uint8_t* opcode) {
    printf("MOV E, C\n");
    state->pc += 1;
}

void MOV_E_D(State8080* state, const uint8_t* opcode) {
    printf("MOV E, D\n");
    state->pc += 1;
}

void MOV_E_E(State8080* state, const uint8_t* opcode) {
    printf("MOV E, E\n");
    state->pc += 1;
}

void MOV_E_H(State8080* state, const uint8_t* opcode) {
    printf("MOV E, H\n");
    state->pc += 1;
}

void MOV_E_L(State8080* state, const uint8_t* opcode) {
    printf("MOV E, L\n");
    state->pc += 1;
}

void MOV_E_M(State8080* state, const uint8_t* opcode) {
    printf("MOV E, M\n");
    state->pc += 1;
}

void MOV_E_A(State8080* state, const uint8_t* opcode) {
    printf("MOV E, A\n");
    state->pc += 1;
}
#endif
