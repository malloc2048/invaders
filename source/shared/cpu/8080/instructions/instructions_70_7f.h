#ifndef EMULATOR_INSTRUCTIONS_70_7F_H
#define EMULATOR_INSTRUCTIONS_70_7F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_M_B(State8080* state, const uint8_t* opcode) {
    printf("MOV M, B\n");
}

void MOV_M_C(State8080* state, const uint8_t* opcode) {
    printf("MOV M, C\n");
}

void MOV_M_D(State8080* state, const uint8_t* opcode) {
    printf("MOV M, D\n");
}

void MOV_M_E(State8080* state, const uint8_t* opcode) {
    printf("MOV M, E\n");
}

void MOV_M_H(State8080* state, const uint8_t* opcode) {
    printf("MOV M, H\n");
}

void MOV_M_L(State8080* state, const uint8_t* opcode) {
    printf("MOV M, L\n");
}

void HLT(State8080* state, const uint8_t* opcode) {
    printf("HLT\n");
}

void MOV_M_A(State8080* state, const uint8_t* opcode) {
    printf("MOV M, A\n");
}

void MOV_A_B(State8080* state, const uint8_t* opcode) {
    printf("MOV A, B\n");
}

void MOV_A_C(State8080* state, const uint8_t* opcode) {
    printf("MOV A, C\n");
}

void MOV_A_D(State8080* state, const uint8_t* opcode) {
    printf("MOV A, D\n");
}

void MOV_A_E(State8080* state, const uint8_t* opcode) {
    printf("MOV A, E\n");
}

void MOV_A_H(State8080* state, const uint8_t* opcode) {
    printf("MOV A, H\n");
}

void MOV_A_L(State8080* state, const uint8_t* opcode) {
    printf("MOV A, L\n");
}

void MOV_A_M(State8080* state, const uint8_t* opcode) {
    printf("MOV A, M\n");
}

void MOV_A_A(State8080* state, const uint8_t* opcode) {
    printf("MOV A, A\n");
}
#endif
