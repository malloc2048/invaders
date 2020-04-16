#ifndef EMULATOR_BRANCH_GROUP_H
#define EMULATOR_BRANCH_GROUP_H

#include <cstdio>
#include "cpu/8080/state.h"

/*
 * Conditions:
 * NZ - not zero (z = 0)
 *  Z - zero (z = 1)
 * NC - no carry (cy = 0)
 *  C - carry (cy = 1)
 * PO - parity odd (p = 0)
 * PE - parity even (p = 1)
 *  P - plus (s = 0)
 *  M - minus (s = 1)
 */

// JMP addr jump (PC) <-(byte 3)(byte 2)
void JMP(State8080 *state);

// J<condition> addr conditional jump (see conditions)
// if(condition) (PC) <- (byte 3)(byte 2)
void JNZ(State8080 *state);

// CALL addr call
// ((SP) - 1) <- (PCH) ((SP) - 2) <- (PCL)
// (SP) <- (SP) - 2 (PC) <- (byte 3)(byte 2)
void CALL(State8080 *state);

// C<condition> addr condition call (see conditions)

// RET return
// (PCL) <- ((SP)) (PCL) <- ((SP) + 1) (SP) <- (SP) + 2
void RET(State8080* state);

// R<condition> (see conditions) (see conditions)
// RST restart
// PCHL jump H and L indirect - move H and L to PC
#endif
