#ifndef EMULATOR_INSTRUCTIONS_A0_AF_H
#define EMULATOR_INSTRUCTIONS_A0_AF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void ANAB(State8080* state, const uint8_t* opcode) {
    printf("ANA B\n");
    state->pc += 1;
}

void ANAC(State8080* state, const uint8_t* opcode) {
    printf("ANA C\n");
    state->pc += 1;
}

void ANAD(State8080* state, const uint8_t* opcode) {
    printf("ANA D\n");
    state->pc += 1;
}

void ANAE(State8080* state, const uint8_t* opcode) {
    printf("ANA E\n");
    state->pc += 1;
}

void ANAH(State8080* state, const uint8_t* opcode) {
    printf("ANA H\n");
    state->pc += 1;
}

void ANAL(State8080* state, const uint8_t* opcode) {
    printf("ANA L\n");
    state->pc += 1;
}

void ANAM(State8080* state, const uint8_t* opcode) {
    printf("ANA M\n");
    state->pc += 1;
}

void ANAA(State8080* state, const uint8_t* opcode) {
    printf("ANA A\n");
    state->pc += 1;
}

void XRAB(State8080* state, const uint8_t* opcode) {
    printf("XRA B\n");
    state->pc += 1;
}

void XRAC(State8080* state, const uint8_t* opcode) {
    printf("XRA C\n");
    state->pc += 1;
}

void XRAD(State8080* state, const uint8_t* opcode) {
    printf("XRA D\n");
    state->pc += 1;
}

void XRAE(State8080* state, const uint8_t* opcode) {
    printf("XRA E\n");
    state->pc += 1;
}

void XRAH(State8080* state, const uint8_t* opcode) {
    printf("XRA H\n");
    state->pc += 1;
}

void XRAL(State8080* state, const uint8_t* opcode) {
    printf("XRA L\n");
    state->pc += 1;
}

void XRAM(State8080* state, const uint8_t* opcode) {
    printf("XRA M\n");
    state->pc += 1;
}

void XRAA(State8080* state, const uint8_t* opcode) {
    printf("XRA A\n");
    state->pc += 1;
}
#endif
