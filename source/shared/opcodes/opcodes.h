#ifndef EMULATOR_OPCODES_H
#define EMULATOR_OPCODES_H

#include <cstdio>
#include "opcode.h"

void Load(FILE* cfgFile);
struct OpCode* GetOpCode(uint8_t code);
#endif
