#ifndef EMULATOR_INSTRUCTIONS_60_6F_H
#define EMULATOR_INSTRUCTIONS_60_6F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_H_B(State8080* state, const uint8_t* opcode) {
    printf("MOV H, B\n");
    state->pc += 1;
    state->pc += 1;
}

void MOV_H_C(State8080* state, const uint8_t* opcode) {
    printf("MOV H, C\n");
    state->pc += 1;
}

void MOV_H_D(State8080* state, const uint8_t* opcode) {
    printf("MOV H, D\n");
    state->pc += 1;
}

void MOV_H_E(State8080* state, const uint8_t* opcode) {
    printf("MOV H, E\n");
    state->pc += 1;
}

void MOV_H_H(State8080* state, const uint8_t* opcode) {
    printf("MOV H, H\n");
    state->pc += 1;
}

void MOV_H_L(State8080* state, const uint8_t* opcode) {
    printf("MOV H, L\n");
    state->pc += 1;
}

void MOV_H_M(State8080* state, const uint8_t* opcode) {
    printf("MOV H, M\n");
    state->pc += 1;
}

void MOV_H_A(State8080* state, const uint8_t* opcode) {
    printf("MOV H, A\n");
    state->pc += 1;
}

void MOV_L_B(State8080* state, const uint8_t* opcode) {
    printf("MOV L, B\n");
    state->pc += 1;
}

void MOV_L_C(State8080* state, const uint8_t* opcode) {
    printf("MOV L, C\n");
    state->pc += 1;
}

void MOV_L_D(State8080* state, const uint8_t* opcode) {
    printf("MOV L, D\n");
    state->pc += 1;
}

void MOV_L_E(State8080* state, const uint8_t* opcode) {
    printf("MOV L, E\n");
    state->pc += 1;
}

void MOV_L_H(State8080* state, const uint8_t* opcode) {
    printf("MOV L, H\n");
    state->pc += 1;
}

void MOV_L_L(State8080* state, const uint8_t* opcode) {
    printf("MOV L, L\n");
    state->pc += 1;
}

void MOV_L_M(State8080* state, const uint8_t* opcode) {
    printf("MOV L, M\n");
    state->pc += 1;
}

void MOV_L_A(State8080* state, const uint8_t* opcode) {
    printf("MOV L, A\n");
    state->pc += 1;
}
#endif
