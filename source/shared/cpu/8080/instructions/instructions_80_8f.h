#ifndef EMULATOR_INSTRUCTIONS_80_8F_H
#define EMULATOR_INSTRUCTIONS_80_8F_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void ADDB(State8080* state, const uint8_t* opcode) {
    printf("ADD B\n");
    uint16_t answer = (uint16_t) state->a + state->b;
    state->cc.z = (answer & 0xff) == 0;
}

void ADDC(State8080* state, const uint8_t* opcode) {
    printf("ADD C\n");
}

void ADDD(State8080* state, const uint8_t* opcode) {
    printf("ADD D\n");
}

void ADDE(State8080* state, const uint8_t* opcode) {
    printf("ADD E\n");
}

void ADDH(State8080* state, const uint8_t* opcode) {
    printf("ADD H\n");
}

void ADDL(State8080* state, const uint8_t* opcode) {
    printf("ADD L\n");
}

void ADDM(State8080* state, const uint8_t* opcode) {
    printf("ADD M\n");
}

void ADDA(State8080* state, const uint8_t* opcode) {
    printf("ADD A\n");
}

void ADCB(State8080* state, const uint8_t* opcode) {
    printf("ADC B\n");
}

void ADCC(State8080* state, const uint8_t* opcode) {
    printf("ADC C\n");
}

void ADCD(State8080* state, const uint8_t* opcode) {
    printf("ADC D\n");
}

void ADCE(State8080* state, const uint8_t* opcode) {
    printf("ADC E\n");
}

void ADCH(State8080* state, const uint8_t* opcode) {
    printf("ADC H\n");
}

void ADCL(State8080* state, const uint8_t* opcode) {
    printf("ADC L\n");
}

void ADCM(State8080* state, const uint8_t* opcode) {
    printf("ADC M\n");
}

void ADCA(State8080* state, const uint8_t* opcode) {
    printf("ADC A\n");
}
#endif
