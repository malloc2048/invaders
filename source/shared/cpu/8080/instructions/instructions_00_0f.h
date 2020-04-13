#ifndef EMULATOR_INSTRUCTIONS_00_0F_H
#define EMULATOR_INSTRUCTIONS_00_0F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void NOP(State8080* state, const uint8_t* opcode) {
    printf("NOP\n");
}

void LXIB(State8080* state, const uint8_t* opcode) {
    state->c = opcode[1];
    state->b = opcode[2];
    state->pc += 2;
}

void STAXB(State8080* state, const uint8_t* opcode) {
    printf("STAX B\n");
}

void INXB(State8080* state, const uint8_t* opcode) {
    printf("INX B\n");
}

void INRB(State8080* state, const uint8_t* opcode) {
    printf("INR B\n");
}

void DCRB(State8080* state, const uint8_t* opcode) {
    printf("DCR B\n");
}

void MVIB(State8080* state, const uint8_t* opcode) {
    printf("MVI B\n");
    state->pc += 1;
}

void RLC(State8080* state, const uint8_t* opcode) {
    printf("RLC\n");
}

void DADB(State8080* state, const uint8_t* opcode) {
    printf("DAD B\n");
}

void LDAXB(State8080* state, const uint8_t* opcode) {
    printf("LDAX B\n");
}

void DCXB(State8080* state, const uint8_t* opcode) {
    printf("DCX B\n");
}

void INRC(State8080* state, const uint8_t* opcode) {
    printf("INR C\n");
}

void DCRC(State8080* state, const uint8_t* opcode) {
    printf("DCR C\n");
}

void MVIC(State8080* state, const uint8_t* opcode) {
    printf("MVI C\n");
    state->pc += 1;
}

void RRC(State8080* state, const uint8_t* opcode) {
    printf("RRC\n");
}
#endif
