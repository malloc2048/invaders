#ifndef EMULATOR_INSTRUCTIONS_20_2F_H
#define EMULATOR_INSTRUCTIONS_20_2F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void LXIH(State8080* state, const uint8_t* opcode) {
    printf("LXI H\n");
    state->pc += 3;
}

void SHLD(State8080* state, const uint8_t* opcode) {
    printf("SHLD\n");
    state->pc += 3;
}

void INXH(State8080* state, const uint8_t* opcode) {
    printf("INX H\n");
    state->pc += 3;
}

void INRH(State8080* state, const uint8_t* opcode) {
    printf("INR H\n");
    state->pc += 3;
}

void DCRH(State8080* state, const uint8_t* opcode) {
    printf("DCR H\n");
    state->pc += 3;
}

void MVIH(State8080* state, const uint8_t* opcode) {
    printf("MVI H\n");
    state->pc += 3;
}

void DAA(State8080* state, const uint8_t* opcode) {
    printf("DAA\n");
    state->pc += 3;
}

void DADH(State8080* state, const uint8_t* opcode) {
    printf("DAD H\n");
    state->pc += 3;
}

void LHLD(State8080* state, const uint8_t* opcode) {
    printf("LHLD\n");
    state->pc += 3;
}

void DCXH(State8080* state, const uint8_t* opcode) {
    printf("DCXH\n");
    state->pc += 3;
}

void INRL(State8080* state, const uint8_t* opcode) {
    printf("INR L\n");
    state->pc += 3;
}

void DCRL(State8080* state, const uint8_t* opcode) {
    printf("DCR L\n");
    state->pc += 3;
}

void MVIL(State8080* state, const uint8_t* opcode) {
    printf("MVI L\n");
    state->pc += 3;
}

void CMA(State8080* state, const uint8_t* opcode) {
    printf("CMA\n");
    state->pc += 3;
}
#endif
