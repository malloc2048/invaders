#ifndef EMULATOR_INSTRUCTIONS_B0_BF_H
#define EMULATOR_INSTRUCTIONS_B0_BF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void ORAB(State8080* state, const uint8_t* opcode) {
    printf("ORA B\n");
    state->pc += 1;
}

void ORAC(State8080* state, const uint8_t* opcode) {
    printf("ORA C\n");
    state->pc += 1;
}

void ORAD(State8080* state, const uint8_t* opcode) {
    printf("ORA D\n");
    state->pc += 1;
}

void ORAE(State8080* state, const uint8_t* opcode) {
    printf("ORA E\n");
    state->pc += 1;
}

void ORAH(State8080* state, const uint8_t* opcode) {
    printf("ORA H\n");
    state->pc += 1;
}

void ORAL(State8080* state, const uint8_t* opcode) {
    printf("ORA L\n");
    state->pc += 1;
}

void ORAM(State8080* state, const uint8_t* opcode) {
    printf("ORA M\n");
    state->pc += 1;
}

void ORAA(State8080* state, const uint8_t* opcode) {
    printf("ORA A\n");
    state->pc += 1;
}

void CMPB(State8080* state, const uint8_t* opcode) {
    printf("CMP B\n");
    state->pc += 1;
}

void CMPC(State8080* state, const uint8_t* opcode) {
    printf("CMP C\n");
    state->pc += 1;
}

void CMPD(State8080* state, const uint8_t* opcode) {
    printf("CMP D\n");
    state->pc += 1;
}

void CMPE(State8080* state, const uint8_t* opcode) {
    printf("CMP E\n");
    state->pc += 1;
}

void CMPH(State8080* state, const uint8_t* opcode) {
    printf("CMP H\n");
    state->pc += 1;
}

void CMPL(State8080* state, const uint8_t* opcode) {
    printf("CMP L\n");
    state->pc += 1;
}

void CMPM(State8080* state, const uint8_t* opcode) {
    printf("CMP M\n");
    state->pc += 1;
}

void CMPA(State8080* state, const uint8_t* opcode) {
    printf("CMP A\n");
    state->pc += 1;
}
#endif
