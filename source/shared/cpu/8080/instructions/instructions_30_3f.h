#ifndef EMULATOR_INSTRUCTIONS_30_3F_H
#define EMULATOR_INSTRUCTIONS_30_3F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void LXISP(State8080* state, const uint8_t* opcode) {
    printf("LXI SP\n");
    state->pc += 3;
}

void STA(State8080* state, const uint8_t* opcode) {
    printf("STA\n");
    state->pc += 3;
}

void INXSP(State8080* state, const uint8_t* opcode) {
    printf("INX SP\n");
    state->pc += 1;
}

void INRM(State8080* state, const uint8_t* opcode) {
    printf("INR M\n");
    state->pc += 1;
}

void DCRM(State8080* state, const uint8_t* opcode) {
    printf("DCR M\n");
    state->pc += 1;
}

void MVIM(State8080* state, const uint8_t* opcode) {
    printf("MVI M\n");
    state->pc += 2;
}

void STC(State8080* state, const uint8_t* opcode) {
    printf("STC\n");
    state->pc += 1;
}

void DADSP(State8080* state, const uint8_t* opcode) {
    printf("DAD SP\n");
    state->pc += 1;
}

void LDA(State8080* state, const uint8_t* opcode) {
    printf("LDA\n");
    state->pc += 3;
}

void DCXSP(State8080* state, const uint8_t* opcode) {
    printf("DCX SP\n");
    state->pc += 1;
}

void INRA(State8080* state, const uint8_t* opcode) {
    printf("INR A\n");
    state->pc += 1;
}

void DCRA(State8080* state, const uint8_t* opcode) {
    printf("DCR A\n");
    state->pc += 1;
}

void MVIA(State8080* state, const uint8_t* opcode) {
    printf("MVI A\n");
    state->pc += 2;
}

void CMC(struct State8080* state, const uint8_t* opcode) {
    printf("CMC\n");
    state->pc += 1;
}
#endif
