#ifndef EMULATOR_INSTRUCTIONS_90_9F_H
#define EMULATOR_INSTRUCTIONS_90_9F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void SUBB(State8080* state, const uint8_t* opcode) {
    printf("SUB B\n");
}

void SUBC(State8080* state, const uint8_t* opcode) {
    printf("SUB C\n");
}

void SUBD(State8080* state, const uint8_t* opcode) {
    printf("SUB D\n");
}

void SUBE(State8080* state, const uint8_t* opcode) {
    printf("SUB E\n");
}

void SUBH(State8080* state, const uint8_t* opcode) {
    printf("SUB H\n");
}

void SUBL(State8080* state, const uint8_t* opcode) {
    printf("SUB L\n");
}

void SUBM(State8080* state, const uint8_t* opcode) {
    printf("SUB M\n");
}

void SUBA(State8080* state, const uint8_t* opcode) {
    printf("SUB A\n");
}

void SBBB(State8080* state, const uint8_t* opcode) {
    printf("SBB B\n");
}

void SBBC(State8080* state, const uint8_t* opcode) {
    printf("SBB C\n");
}

void SBBD(State8080* state, const uint8_t* opcode) {
    printf("SBB D\n");
}

void SBBE(State8080* state, const uint8_t* opcode) {
    printf("SBB E\n");
}

void SBBH(State8080* state, const uint8_t* opcode) {
    printf("SBB H\n");
}

void SBBL(State8080* state, const uint8_t* opcode) {
    printf("SBB L\n");
}

void SBBM(State8080* state, const uint8_t* opcode) {
    printf("SBB M\n");
}

void SBBA(State8080* state, const uint8_t* opcode) {
    printf("SBB A\n");
}
#endif
