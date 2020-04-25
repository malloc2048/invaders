#ifndef NESEMU_INTEL8080_H
#define NESEMU_INTEL8080_H

#include <memory>
#include <string>
#include "flags.h"
#include "opcode.h"
#include "ram/ram.h"
#include "registers.h"

class Intel8080 {
public:
    Intel8080();
    ~Intel8080() = default;

    void cycle();

private:
    std::shared_ptr<RAM> ram;
    std::shared_ptr<Flags> flags;
    std::shared_ptr<Registers> registers;
    std::shared_ptr<OpCode> opcodes[256];
};
#endif
