#ifndef EMULATOR_INSTRUCTIONS_60_6F_H
#define EMULATOR_INSTRUCTIONS_60_6F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void MOV_H_B(State8080* state, const uint8_t* opcode) {
    printf("MOV H, B\n");
}

void MOV_H_C(State8080* state, const uint8_t* opcode) {
    printf("MOV H, C\n");
}

void MOV_H_D(State8080* state, const uint8_t* opcode) {
    printf("MOV H, D\n");
}

void MOV_H_E(State8080* state, const uint8_t* opcode) {
    printf("MOV H, E\n");
}

void MOV_H_H(State8080* state, const uint8_t* opcode) {
    printf("MOV H, H\n");
}

void MOV_H_L(State8080* state, const uint8_t* opcode) {
    printf("MOV H, L\n");
}

void MOV_H_M(State8080* state, const uint8_t* opcode) {
    printf("MOV H, M\n");
}

void MOV_H_A(State8080* state, const uint8_t* opcode) {
    printf("MOV H, A\n");
}

void MOV_L_B(State8080* state, const uint8_t* opcode) {
    printf("MOV L, B\n");
}

void MOV_L_C(State8080* state, const uint8_t* opcode) {
    printf("MOV L, C\n");
}

void MOV_L_D(State8080* state, const uint8_t* opcode) {
    printf("MOV L, D\n");
}

void MOV_L_E(State8080* state, const uint8_t* opcode) {
    printf("MOV L, E\n");
}

void MOV_L_H(State8080* state, const uint8_t* opcode) {
    printf("MOV L, H\n");
}

void MOV_L_L(State8080* state, const uint8_t* opcode) {
    printf("MOV L, L\n");
}

void MOV_L_M(State8080* state, const uint8_t* opcode) {
    printf("MOV L, M\n");
}

void MOV_L_A(State8080* state, const uint8_t* opcode) {
    printf("MOV L, A\n");
}
#endif
