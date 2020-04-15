#ifndef EMULATOR_STACK_IO_GROUP_H
#define EMULATOR_STACK_IO_GROUP_H

#include <cstdio>
#include <cstdlib>
#include "cpu/8080/state.h"

void NoOp(State8080 *state);

void PopH(State8080* state);

void PushBC(State8080* state);
void PushDE(State8080* state);
void PushHL(State8080* state);
void UnimplementedInstruction(State8080 *state);

void Out(State8080* state);
#endif
