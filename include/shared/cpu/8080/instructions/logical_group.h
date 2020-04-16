#ifndef EMULATOR_LOGICAL_GROUP_H
#define EMULATOR_LOGICAL_GROUP_H

#include <cstdio>
#include "cpu/8080/state.h"

// ANA r AND register
// ANA M AND memory
// ANI data AND immediate
// XRA r exclusive OR register
// XRA M exclusive OR memory
// XRI data exclusive OR immediate
// ORA r OR register
// ORA M OR memory
// ORI data OR immediate
// CMP r compare register
// CMP M compare memory

// CPI data compare immediate (A) - (byte 2)
// content of second byte is subtracted from accumulator
// Flags:
//   Zero set to 1 when (A) == (byte 2)
//   CarrY set to 1 when (A) < (byte 2)
void CPI(State8080* state);

// RLC rotate left
// RRC rotate right
// RAL rotate left through carry
// RRA rotate right through carry
// CMA complement accumulator
// CMC complement carry
// STC set carry
#endif
