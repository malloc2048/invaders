#ifndef EMULATOR_INSTRUCTIONS_80_8F_H
#define EMULATOR_INSTRUCTIONS_80_8F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"
#include "common/utilities.h"

void ADDB(State8080 *state, const uint8_t *opcode) {
#if DEBUG_ON == 1
    printf("ADD B\n");
#endif
    uint16_t answer = (uint16_t)state->a + (uint16_t)state->b;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = ((answer > 0xff) == 0);
    state->cc.p = Parity(answer & 0xff, 8);
    state->a = answer & 0xff;
    state->pc += 1;
}

void ADDC(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADD C\n");
#endif
state->pc += 1;
}

void ADDD(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADD D\n");
#endif
state->pc += 1;
}

void ADDE(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADD E\n");
#endif
state->pc += 1;
}

void ADDH(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADD H\n");
#endif
state->pc += 1;
}

void ADDL(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADD L\n");
#endif
state->pc += 1;
}

void ADDM(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADD M\n");
#endif
state->pc += 1;
}

void ADDA(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADD A\n");
#endif
state->pc += 1;
}

void ADCB(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC B\n");
#endif
state->pc += 1;
}

void ADCC(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC C\n");
#endif
state->pc += 1;
}

void ADCD(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC D\n");
#endif
state->pc += 1;
}

void ADCE(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC E\n");
#endif
state->pc += 1;
}

void ADCH(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC H\n");
#endif
state->pc += 1;
}

void ADCL(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC L\n");
#endif
state->pc += 1;
}

void ADCM(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC M\n");
#endif
state->pc += 1;
}

void ADCA(State8080* state, const uint8_t* opcode) {
#if DEBUG_ON == 1
    printf("ADC A\n");
#endif
state->pc += 1;
}
#endif
