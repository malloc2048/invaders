#ifndef EMULATOR_BRANCH_GROUP_H
#define EMULATOR_BRANCH_GROUP_H

#include <cstdio>
#include "cpu/8080/state.h"

void Jump(State8080 *state);
void Call(State8080 *state);
void Return(State8080* state);
void JumpNotZero(State8080 *state);
#endif
