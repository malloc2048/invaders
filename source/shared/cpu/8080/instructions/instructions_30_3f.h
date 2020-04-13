#ifndef EMULATOR_INSTRUCTIONS_30_3F_H
#define EMULATOR_INSTRUCTIONS_30_3F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void LXISP(State8080* state, const uint8_t* opcode) {
    printf("LXI SP\n");
    state->pc += 2;
}

void STA(State8080* state, const uint8_t* opcode) {
    printf("STA\n");
    state->pc += 2;
}

void INXSP(State8080* state, const uint8_t* opcode) {
    printf("INX SP\n");
}

void INRM(State8080* state, const uint8_t* opcode) {
    printf("INR M\n");
}

void DCRM(State8080* state, const uint8_t* opcode) {
    printf("DCR M\n");
}

void MVIM(State8080* state, const uint8_t* opcode) {
    printf("MVI M\n");
    state->pc += 1;
}

void STC(State8080* state, const uint8_t* opcode) {
    printf("STC\n");
}

void DADSP(State8080* state, const uint8_t* opcode) {
    printf("DAD SP\n");
}

void LDA(State8080* state, const uint8_t* opcode) {
    printf("LDA\n");
    state->pc += 2;
}

void DCXSP(State8080* state, const uint8_t* opcode) {
    printf("DCX SP\n");
}

void INRA(State8080* state, const uint8_t* opcode) {
    printf("INR A\n");
}

void DCRA(State8080* state, const uint8_t* opcode) {
    printf("DCR A\n");
}

void MVIA(State8080* state, const uint8_t* opcode) {
    printf("MVI A\n");
    state->pc += 1;
}

void CMC(struct State8080* state, const uint8_t* opcode) {
    printf("CMC\n");
}
#endif
