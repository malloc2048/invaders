#ifndef NESEMU_OPCODE_H
#define NESEMU_OPCODE_H

#include <memory>
#include <string>
#include "flags.h"
#include "ram/ram.h"
#include "registers.h"

class OpCode {
public:
    OpCode() = default;
    ~OpCode() = default;

    // Returns the number of memory locations used in the instruction
    virtual int8_t Execute() = 0;

protected:
    uint8_t opcode = 0x00;
    std::string nemonic = std::string();

    std::shared_ptr<RAM> ram;
    std::shared_ptr<Flags> flags;
    std::shared_ptr<Registers> registers;
};
#endif
