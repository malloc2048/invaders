#ifndef EMULATOR_INSTRUCTIONS_00_0F_H
#define EMULATOR_INSTRUCTIONS_00_0F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "cpu/8080/state.h"

void NOP(State8080 *state, const uint8_t *opcode) {
    printf("NOP\n");
    state->pc += 1;
}

void LXIB(State8080 *state, const uint8_t *opcode) {
    printf("LXI B\n");
    state->c = opcode[1];
    state->b = opcode[2];
    state->pc += 3;
}

void STAXB(State8080 *state, const uint8_t *opcode) {
    printf("STAX B\n");
    state->pc += 1;
}

void INXB(State8080 *state, const uint8_t *opcode) {
    printf("INX B\n");
    state->pc += 1;
}

void INRB(State8080 *state, const uint8_t *opcode) {
    printf("INR B\n");
    state->pc += 1;
}

void DCRB(State8080 *state, const uint8_t *opcode) {
    printf("DCR B\n");
    state->pc += 1;
}

void MVIB(State8080 *state, const uint8_t *opcode) {
    printf("MVI B\n");
    state->pc += 2;
}

void RLC(State8080 *state, const uint8_t *opcode) {
    printf("RLC\n");
    state->pc += 1;
}

void DADB(State8080 *state, const uint8_t *opcode) {
    printf("DAD B\n");
    state->pc += 1;
}

void LDAXB(State8080 *state, const uint8_t *opcode) {
    printf("LDAX B\n");
    state->pc += 1;
}

void DCXB(State8080 *state, const uint8_t *opcode) {

    printf("DCX B\n");

    state->pc += 1;
}

void INRC(State8080 *state, const uint8_t *opcode) {

    printf("INR C\n");

    state->pc += 1;
}

void DCRC(State8080 *state, const uint8_t *opcode) {

    printf("DCR C\n");

    state->pc += 1;
}

void MVIC(State8080 *state, const uint8_t *opcode) {

    printf("MVI C\n");

    state->pc += 2;
}

void RRC(State8080 *state, const uint8_t *opcode) {

    printf("RRC\n");

    state->pc += 1;
}
#endif
