#ifndef EMULATOR_DATA_TRANSFER_GROUP_H
#define EMULATOR_DATA_TRANSFER_GROUP_H

#include <cstdio>
#include "cpu/8080/state.h"

// MOV r1, r2 - move register
// content of r2 is moved to r1 - (r1) <- (r2)
void MOV_H_A(State8080* state);
void MOV_L_A(State8080* state);

// MOV M, r move to memory
// content of register r is moved to memory location whose address is in H and L - ((H)(L)) <- (r)
void MOV_M_A(State8080* state);

// move to memory immediate
// content of byte 2 of instruction is moved to memory location whose address is in H and L
// MVI M, data ((H)(L)) <- (byte 2)
void MVI_B(State8080* state);
void MVI_C(State8080* state);
void MVI_D(State8080* state);
void MVI_E(State8080* state);
void MVI_H(State8080* state);
void MVI_L(State8080* state);
void MVI_M(State8080* state);
void MVI_A(State8080* state);

// LXI rp, data 16 - load register pair immediate
// byte 3 of the instruction is moved to high order register (rh) <- (byte 3)
// byte 2 of the instruction is moved to low order register (rl) <- (byte 2)
void LXI_B(State8080* state);
void LXI_D(State8080* state);
void LXI_H(State8080* state);
void LXI_SP(State8080* state);

// LDA addr load accumulator direct
// content of memory location address specified in byte 2 and byte 3 of the instruction is moved to register A
// LDA addr (A) <- ((byte 3)(byte 2))
void LDA(State8080* state);

// STA addr
// LHLD addr
// SHLD addr

// LDAX rp load accumulator indirect
// content of memory address in register pair rp, is moved to register A - (A) <- ((rp))
void LDAX_B(State8080* state);
void LDAX_D(State8080* state);

// STAX rp store accumulator indirect
// content of register A is moved to memory location address in rp

// XCHG exchange H and L with D and E
// contents of registers H and L are exchanged with contents of registers D and E - (H) <-> (D) (L) <-> (E)
void XCHG(State8080* state);
#endif
