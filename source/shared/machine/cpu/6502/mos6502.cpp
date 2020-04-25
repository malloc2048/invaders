#include "mos6502.h"

void MOS6502::cycle() {
    auto opcode = ram->read(registers->pc);
    opcodes[opcode]->Execute();
}
