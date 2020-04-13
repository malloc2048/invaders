#ifndef EMULATOR_INSTRUCTIONS_40_4F_H
#define EMULATOR_INSTRUCTIONS_40_4F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_B_B(State8080* state, const uint8_t* opcode) {
    printf("MOV B, B\n");
}

void MOV_B_C(State8080* state, const uint8_t* opcode) {
    printf("MOV B, C\n");
}

void MOV_B_D(State8080* state, const uint8_t* opcode) {
    printf("MOV B, D\n");
}

void MOV_B_E(State8080* state, const uint8_t* opcode) {
    printf("MOV B, E\n");
}

void MOV_B_H(State8080* state, const uint8_t* opcode) {
    printf("MOV B, H\n");
}

void MOV_B_L(State8080* state, const uint8_t* opcode) {
    printf("MOV B, L\n");
}

void MOV_B_M(State8080* state, const uint8_t* opcode) {
    printf("MOV B, M\n");
}

void MOV_B_A(State8080* state, const uint8_t* opcode) {
    printf("MOV B, A\n");
}

void MOV_C_B(State8080* state, const uint8_t* opcode) {
    printf("MOV C, B\n");
}

void MOV_C_C(State8080* state, const uint8_t* opcode) {
    printf("MOV C, C\n");
}

void MOV_C_D(State8080* state, const uint8_t* opcode) {
    printf("MOV C, D\n");
}

void MOV_C_E(State8080* state, const uint8_t* opcode) {
    printf("MOV C, E\n");
}

void MOV_C_H(State8080* state, const uint8_t* opcode) {
    printf("MOV C, H\n");
}

void MOV_C_L(State8080* state, const uint8_t* opcode) {
    printf("MOV C, L\n");
}

void MOV_C_M(State8080* state, const uint8_t* opcode) {
    printf("MOV C, M\n");
}

void MOV_C_A(State8080* state, const uint8_t* opcode) {
    printf("MOV C, A\n");
}
#endif
