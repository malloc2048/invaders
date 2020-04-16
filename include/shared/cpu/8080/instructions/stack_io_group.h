#ifndef EMULATOR_STACK_IO_GROUP_H
#define EMULATOR_STACK_IO_GROUP_H

#include <cstdio>
#include <cstdlib>
#include "cpu/8080/state.h"

// PUSH rp push
// ((SP) - 1) <- (rh) ((SP) - 2) <- (rl) (SP) <- (SP) - 2
void PUSH_B(State8080* state);
void PUSH_D(State8080* state);
void PUSH_H(State8080* state);

// PUSH PSW push processor status word

// POP rp pop
// (rl) <- ((SP)) (rh) <- ((SP) + 1) (SP) <- (SP) + 2
void POP_B(State8080* state);
void POP_D(State8080* state);
void POP_H(State8080* state);

// POP PSW pop processor status word
// XTHL exchange stack top with H and L
// SPHL move HL to SP
// IN port Input

// OUT port Output (data) <- (A)
// content of register A is placed on the eight bit bi-directinal data bus for transmission to the specified port
void Out(State8080* state);

// EI Enable Interrupts
// DI Disable Interrupts
// HLT Halt

// NOP No op
void NOP(State8080 *state);

void UnimplementedInstruction(State8080 *state);
#endif
