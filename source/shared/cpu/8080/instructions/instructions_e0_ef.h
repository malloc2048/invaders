#ifndef EMULATOR_INSTRUCTIONS_E0_EF_H
#define EMULATOR_INSTRUCTIONS_E0_EF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void RPO(State8080* state, const uint8_t* opcode) {
    printf("RPO\n");
    state->pc += 1;
}

void POPH(State8080* state, const uint8_t* opcode) {
    printf("POP H\n");
    state->pc += 1;
}

void JPO(State8080* state, const uint8_t* opcode) {
    printf("JPO\n");
    state->pc += 2;
    state->pc += 1;
}

void XTHL(State8080* state, const uint8_t* opcode) {
    printf("XTHL\n");
    state->pc += 1;
}

void CPO(State8080* state, const uint8_t* opcode) {
    printf("CPO\n");
    state->pc += 2;
    state->pc += 1;
}

void PUSHH(State8080* state, const uint8_t* opcode) {
    printf("PUSH H\n");
    state->pc += 1;
}

void ANI(State8080* state, const uint8_t* opcode) {
    printf("ANI\n");
    state->pc += 1;
    state->pc += 1;
}

void RST4(State8080* state, const uint8_t* opcode) {
    printf("RST 4\n");
    state->pc += 1;
}

void RPE(State8080* state, const uint8_t* opcode) {
    printf("RPE\n");
    state->pc += 1;
}

void PCHL(State8080* state, const uint8_t* opcode) {
    printf("PCHL\n");
    state->pc += 1;
}

void JPE(State8080* state, const uint8_t* opcode) {
    printf("JPE\n");
    state->pc += 2;
    state->pc += 1;
}

void XCHG(State8080* state, const uint8_t* opcode) {
    printf("XCHG\n");
    state->pc += 1;
}

void CPE(State8080* state, const uint8_t* opcode) {
    printf("CPE \n");
    state->pc += 2;
    state->pc += 1;
}

void XRI(State8080* state, const uint8_t* opcode) {
    printf("XRI\n");
    state->pc += 1;
    state->pc += 1;
}

void RST5(State8080* state, const uint8_t* opcode) {
    printf("RST5\n");
    state->pc += 1;
}
#endif
