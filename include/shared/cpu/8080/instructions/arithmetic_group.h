#ifndef EMULATOR_ARITHMETIC_GROUP_H
#define EMULATOR_ARITHMETIC_GROUP_H

#include <cstdio>
#include "cpu/8080/state.h"

// ADD r add register
// content of register r is added to content of accumulator, result stored in A (A) <- (A) + (r)
// Flags: Zero Sign Parity CarrY Auxiliary Carry

// ADD M add memory
// ADI data add immediate
// ADC r add register with carry
// ADC M add memory with carry
// ACI data add immediate with carry
// SUB r subtract register
// SUB M subtract memory Flags: Zero Sign Parity CarrY Auxiliary Carry
// SUI data subtract immediate Flags: Zero Sign Parity CarrY Auxiliary Carry
// SBB r subtract register with borrow Flags: Zero Sign Parity CarrY Auxiliary Carry
// SBB M subtract memory with borrow Flags: Zero Sign Parity CarrY Auxiliary Carry
// SBI data subtract immediate with borrow Flags: Zero Sign Parity CarrY Auxiliary Carry
// INR r increment register Flags: Zero Sign Parity Auxiliary Carry
// INR M increment memory Flags: Zero Sign Parity Auxiliary Carry

// DCR r decrement register (r) <- (r) - 1
// Flags: Zero Sign Parity Auxiliary Carry
void DCR_B(State8080* state);
void DCR_C(State8080* state);

// DCR M decrement memory Flags: Zero Sign Parity Auxiliary Carry

// INX rp increment register pair (rh)(rl) <- (rh)(rl) + 1 Flags: none
void INX_D(State8080* state);
void INX_H(State8080* state);

// DCX rp decrement register pair (rh)(rl) <- (rh)(rl) - 1
// Flags: none

// DAD rp add register pair to H and L (rh)(rl) <- (H)(L) + (rh)(rl)
// Flags: CarrY - set if carry out of double precession add
void DAD_B(State8080* state);
void DAD_D(State8080* state);
void DAD_H(State8080* state);

// DAA decimal adjust accumulator

#endif
