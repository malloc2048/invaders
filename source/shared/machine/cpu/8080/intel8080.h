#ifndef NESEMU_INTEL8080_H
#define NESEMU_INTEL8080_H

#include <memory>
#include <string>
#include "flags.h"
#include "opcode.h"
#include <iostream>
#include "registers.h"
#include "machine/ram/ram.h"

class Intel8080 {
public:
    explicit Intel8080(RAM* memory, Flags* flags, Registers* registers, std::ostream& outputStream);
    ~Intel8080() = default;

    void Disassemble();
    void tick(bool showStatus);

private:
    std::ostream& out;
    OpCode* opcodes[256];

    RAM* memory = nullptr;
    Flags* flags = nullptr;
    Registers* registers = nullptr;
};
#endif
