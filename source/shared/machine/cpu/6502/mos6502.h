#ifndef NESEMU_MOS6502_H
#define NESEMU_MOS6502_H

#include <memory>
#include "flags.h"
#include "opcode.h"
#include "registers.h"
#include "machine/ram/ram.h"

class MOS6502 {
public:
    MOS6502() = default;
    ~MOS6502() = default;

    void cycle();

private:
    std::shared_ptr<RAM> ram;
    std::shared_ptr<Flags> flags;
    std::shared_ptr<Registers> registers;
    std::shared_ptr<OpCode> opcodes[256];
};
#endif
