#ifndef EMULATOR_INSTRUCTIONS_40_4F_H
#define EMULATOR_INSTRUCTIONS_40_4F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_B_B(State8080* state, const uint8_t* opcode) {
    printf("MOV B, B\n");
    state->pc += 1;
}

void MOV_B_C(State8080* state, const uint8_t* opcode) {
    printf("MOV B, C\n");
    state->pc += 2;
}

void MOV_B_D(State8080* state, const uint8_t* opcode) {
    printf("MOV B, D\n");
    state->pc += 1;
}

void MOV_B_E(State8080* state, const uint8_t* opcode) {
    printf("MOV B, E\n");
    state->pc += 1;
}

void MOV_B_H(State8080* state, const uint8_t* opcode) {
    printf("MOV B, H\n");
    state->pc += 1;
}

void MOV_B_L(State8080* state, const uint8_t* opcode) {
    printf("MOV B, L\n");
    state->pc += 1;
}

void MOV_B_M(State8080* state, const uint8_t* opcode) {
    printf("MOV B, M\n");
    state->pc += 1;
}

void MOV_B_A(State8080* state, const uint8_t* opcode) {
    printf("MOV B, A\n");
    state->pc += 1;
}

void MOV_C_B(State8080* state, const uint8_t* opcode) {
    printf("MOV C, B\n");
    state->pc += 1;
}

void MOV_C_C(State8080* state, const uint8_t* opcode) {
    printf("MOV C, C\n");
    state->pc += 1;
}

void MOV_C_D(State8080* state, const uint8_t* opcode) {
    printf("MOV C, D\n");
    state->pc += 1;
}

void MOV_C_E(State8080* state, const uint8_t* opcode) {
    printf("MOV C, E\n");
    state->pc += 1;
}

void MOV_C_H(State8080* state, const uint8_t* opcode) {
    printf("MOV C, H\n");
    state->pc += 1;
}

void MOV_C_L(State8080* state, const uint8_t* opcode) {
    printf("MOV C, L\n");
    state->pc += 1;
}

void MOV_C_M(State8080* state, const uint8_t* opcode) {
    printf("MOV C, M\n");
    state->pc += 1;
}

void MOV_C_A(State8080* state, const uint8_t* opcode) {
    printf("MOV C, A\n");
    state->pc += 1;
}
#endif
