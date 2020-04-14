#ifndef EMULATOR_INSTRUCTIONS_90_9F_H
#define EMULATOR_INSTRUCTIONS_90_9F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void SUBB(State8080* state, const uint8_t* opcode) {
    printf("SUB B\n");
    state->pc += 1;
}

void SUBC(State8080* state, const uint8_t* opcode) {
    printf("SUB C\n");
    state->pc += 1;
}

void SUBD(State8080* state, const uint8_t* opcode) {
    printf("SUB D\n");
    state->pc += 1;
}

void SUBE(State8080* state, const uint8_t* opcode) {
    printf("SUB E\n");
    state->pc += 1;
}

void SUBH(State8080* state, const uint8_t* opcode) {
    printf("SUB H\n");
    state->pc += 1;
}

void SUBL(State8080* state, const uint8_t* opcode) {
    printf("SUB L\n");
    state->pc += 1;
}

void SUBM(State8080* state, const uint8_t* opcode) {
    printf("SUB M\n");
    state->pc += 1;
}

void SUBA(State8080* state, const uint8_t* opcode) {
    printf("SUB A\n");
    state->pc += 1;
}

void SBBB(State8080* state, const uint8_t* opcode) {
    printf("SBB B\n");
    state->pc += 1;
}

void SBBC(State8080* state, const uint8_t* opcode) {
    printf("SBB C\n");
    state->pc += 1;
}

void SBBD(State8080* state, const uint8_t* opcode) {
    printf("SBB D\n");
    state->pc += 1;
}

void SBBE(State8080* state, const uint8_t* opcode) {
    printf("SBB E\n");
    state->pc += 1;
}

void SBBH(State8080* state, const uint8_t* opcode) {
    printf("SBB H\n");
    state->pc += 1;
}

void SBBL(State8080* state, const uint8_t* opcode) {
    printf("SBB L\n");
    state->pc += 1;
}

void SBBM(State8080* state, const uint8_t* opcode) {
    printf("SBB M\n");
    state->pc += 1;
}

void SBBA(State8080* state, const uint8_t* opcode) {
    printf("SBB A\n");
    state->pc += 1;
}
#endif
