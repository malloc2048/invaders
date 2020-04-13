#ifndef EMULATOR_INSTRUCTIONS_50_5F_H
#define EMULATOR_INSTRUCTIONS_50_5F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_D_B(State8080* state, const uint8_t* opcode) {
    printf("MOV D, B\n");
}

void MOV_D_C(State8080* state, const uint8_t* opcode) {
    printf("MOV D, C\n");
}

void MOV_D_D(State8080* state, const uint8_t* opcode) {
    printf("MOV D, D\n");
}

void MOV_D_E(State8080* state, const uint8_t* opcode) {
    printf("MOV D, E\n");
}

void MOV_D_H(State8080* state, const uint8_t* opcode) {
    printf("MOV D, H\n");
}

void MOV_D_L(State8080* state, const uint8_t* opcode) {
    printf("MOV D, L\n");
}

void MOV_D_M(State8080* state, const uint8_t* opcode) {
    printf("MOV D, M\n");
}

void MOV_D_A(State8080* state, const uint8_t* opcode) {
    printf("MOV D, A\n");
}

void MOV_E_B(State8080* state, const uint8_t* opcode) {
    printf("MOV E, B\n");
}

void MOV_E_C(State8080* state, const uint8_t* opcode) {
    printf("MOV E, C\n");
}

void MOV_E_D(State8080* state, const uint8_t* opcode) {
    printf("MOV E, D\n");
}

void MOV_E_E(State8080* state, const uint8_t* opcode) {
    printf("MOV E, E\n");
}

void MOV_E_H(State8080* state, const uint8_t* opcode) {
    printf("MOV E, H\n");
}

void MOV_E_L(State8080* state, const uint8_t* opcode) {
    printf("MOV E, L\n");
}

void MOV_E_M(State8080* state, const uint8_t* opcode) {
    printf("MOV E, M\n");
}

void MOV_E_A(State8080* state, const uint8_t* opcode) {
    printf("MOV E, A\n");
}
#endif
