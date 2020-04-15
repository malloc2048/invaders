#ifndef EMULATOR_DATA_TRANSFER_GROUP_H
#define EMULATOR_DATA_TRANSFER_GROUP_H

#include <cstdio>
#include "cpu/8080/state.h"

// MVI M, data ((H)(L)) <- (byte 2)
void MoveImmediateB(State8080* state);
void MoveImmediateC(State8080* state);
void MoveImmediateD(State8080* state);
void MoveImmediateE(State8080* state);
void MoveImmediateH(State8080* state);
void MoveImmediateL(State8080* state);
void MoveImmediateM(State8080* state);
void MoveImmediateA(State8080* state);

// MOV M, A (HL) <- A
void MoveAccumulatorToMemoryHL(State8080* state);

// MOV r1, r2 (r1) <- (r2)
void MoveRegistersHA(State8080* state);
void MoveRegistersLA(State8080* state);

// LXI rp, data 16 (rh) <- (byte 3) (rl) <- (byte 2)
void LoadRegisterPairImmediateBC(State8080* state);
void LoadRegisterPairImmediateDE(State8080* state);
void LoadRegisterPairImmediateHL(State8080* state);
void LoadRegisterPairImmediateSP(State8080* state);

// LDAX rp (A) <- ((rp))
void LoadAccumulatorIndirectBC(State8080* state);
void LoadAccumulatorIndirectDE(State8080* state);

void ExchangeHL_DE(State8080* state);
#endif
