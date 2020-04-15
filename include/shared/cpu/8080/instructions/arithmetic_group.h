#ifndef EMULATOR_ARITHMETIC_GROUP_H
#define EMULATOR_ARITHMETIC_GROUP_H

#include <cstdio>
#include "cpu/8080/state.h"

// INX rp (rh)(rl) <- (rh)(rl) + 1
void IncrementRegisterPairDE(State8080* state);
void IncrementRegisterPairHL(State8080* state);

// DCR r (r) <- (r) - 1
void DecrementRegisterB(State8080* state);

// DAD rp (H)(L) <- (H)(L) + (rh)(rl)
void AddRegisterPairDE(State8080* state);
void AddRegisterPairHL(State8080* state);
#endif
