#ifndef EMULATOR_INSTRUCTIONS_B0_BF_H
#define EMULATOR_INSTRUCTIONS_B0_BF_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "../state.h"

void ORAB(State8080* state, const uint8_t* opcode) {
    printf("ORA B\n");
}

void ORAC(State8080* state, const uint8_t* opcode) {
    printf("ORA C\n");
}

void ORAD(State8080* state, const uint8_t* opcode) {
    printf("ORA D\n");
}

void ORAE(State8080* state, const uint8_t* opcode) {
    printf("ORA E\n");
}

void ORAH(State8080* state, const uint8_t* opcode) {
    printf("ORA H\n");
}

void ORAL(State8080* state, const uint8_t* opcode) {
    printf("ORA L\n");
}

void ORAM(State8080* state, const uint8_t* opcode) {
    printf("ORA M\n");
}

void ORAA(State8080* state, const uint8_t* opcode) {
    printf("ORA A\n");
}

void CMPB(State8080* state, const uint8_t* opcode) {
    printf("CMP B\n");
}

void CMPC(State8080* state, const uint8_t* opcode) {
    printf("CMP C\n");
}

void CMPD(State8080* state, const uint8_t* opcode) {
    printf("CMP D\n");
}

void CMPE(State8080* state, const uint8_t* opcode) {
    printf("CMP E\n");
}

void CMPH(State8080* state, const uint8_t* opcode) {
    printf("CMP H\n");
}

void CMPL(State8080* state, const uint8_t* opcode) {
    printf("CMP L\n");
}

void CMPM(State8080* state, const uint8_t* opcode) {
    printf("CMP M\n");
}

void CMPA(State8080* state, const uint8_t* opcode) {
    printf("CMP A\n");
}
#endif
