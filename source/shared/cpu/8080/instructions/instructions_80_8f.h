#ifndef EMULATOR_INSTRUCTIONS_80_8F_H
#define EMULATOR_INSTRUCTIONS_80_8F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"
#include "common/utilities.h"

void ADDB(State8080* state, const uint8_t* opcode) {
    printf("ADD B\n");
    uint16_t answer = (uint16_t)state->a + (uint16_t)state->b;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = ((answer > 0xff) == 0);
    state->cc.p = Parity(answer & 0xff, 8);
    state->a = answer & 0xff;
    state->pc += 1;
}

void ADDC(State8080* state, const uint8_t* opcode) {
    printf("ADD C\n");
    state->pc += 1;
}

void ADDD(State8080* state, const uint8_t* opcode) {
    printf("ADD D\n");
    state->pc += 1;
}

void ADDE(State8080* state, const uint8_t* opcode) {
    printf("ADD E\n");
    state->pc += 1;
}

void ADDH(State8080* state, const uint8_t* opcode) {
    printf("ADD H\n");
    state->pc += 1;
}

void ADDL(State8080* state, const uint8_t* opcode) {
    printf("ADD L\n");
    state->pc += 1;
}

void ADDM(State8080* state, const uint8_t* opcode) {
    printf("ADD M\n");
    state->pc += 1;
}

void ADDA(State8080* state, const uint8_t* opcode) {
    printf("ADD A\n");
    state->pc += 1;
}

void ADCB(State8080* state, const uint8_t* opcode) {
    printf("ADC B\n");
    state->pc += 1;
}

void ADCC(State8080* state, const uint8_t* opcode) {
    printf("ADC C\n");
    state->pc += 1;
}

void ADCD(State8080* state, const uint8_t* opcode) {
    printf("ADC D\n");
    state->pc += 1;
}

void ADCE(State8080* state, const uint8_t* opcode) {
    printf("ADC E\n");
    state->pc += 1;
}

void ADCH(State8080* state, const uint8_t* opcode) {
    printf("ADC H\n");
    state->pc += 1;
}

void ADCL(State8080* state, const uint8_t* opcode) {
    printf("ADC L\n");
    state->pc += 1;
}

void ADCM(State8080* state, const uint8_t* opcode) {
    printf("ADC M\n");
    state->pc += 1;
}

void ADCA(State8080* state, const uint8_t* opcode) {
    printf("ADC A\n");
    state->pc += 1;
}
#endif
