#ifndef EMULATOR_INSTRUCTIONS_A0_AF_H
#define EMULATOR_INSTRUCTIONS_A0_AF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void ANAB(State8080* state, const uint8_t* opcode) {
    printf("ANA B\n");
}

void ANAC(State8080* state, const uint8_t* opcode) {
    printf("ANA C\n");
}

void ANAD(State8080* state, const uint8_t* opcode) {
    printf("ANA D\n");
}

void ANAE(State8080* state, const uint8_t* opcode) {
    printf("ANA E\n");
}

void ANAH(State8080* state, const uint8_t* opcode) {
    printf("ANA H\n");
}

void ANAL(State8080* state, const uint8_t* opcode) {
    printf("ANA L\n");
}

void ANAM(State8080* state, const uint8_t* opcode) {
    printf("ANA M\n");
}

void ANAA(State8080* state, const uint8_t* opcode) {
    printf("ANA A\n");
}

void XRAB(State8080* state, const uint8_t* opcode) {
    printf("XRA B\n");
}

void XRAC(State8080* state, const uint8_t* opcode) {
    printf("XRA C\n");
}

void XRAD(State8080* state, const uint8_t* opcode) {
    printf("XRA D\n");
}

void XRAE(State8080* state, const uint8_t* opcode) {
    printf("XRA E\n");
}

void XRAH(State8080* state, const uint8_t* opcode) {
    printf("XRA H\n");
}

void XRAL(State8080* state, const uint8_t* opcode) {
    printf("XRA L\n");
}

void XRAM(State8080* state, const uint8_t* opcode) {
    printf("XRA M\n");
}

void XRAA(State8080* state, const uint8_t* opcode) {
    printf("XRA A\n");
}
#endif
