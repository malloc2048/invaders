#ifndef NESEMU_INTEL8080_H
#define NESEMU_INTEL8080_H

#include <memory>
#include <string>
#include "flags.h"
#include "opcode.h"
#include <fstream>
#include <iostream>
#include "registers.h"
#include "machine/ram/ram.h"

class Intel8080 {
public:
    explicit Intel8080(RAM* memory, Flags* flags, Registers* registers, std::ostream& outputStream);
    ~Intel8080() = default;

    void stop();
    void Disassemble();
    void Run(bool showStatus);
    void tick(bool showStatus = false);
    void interrupt(uint8_t interruptNumber);

private:
    std::ostream& out;
    bool halted = true;
    OpCode* opcodes[256];
    std::ofstream debug_output;

    RAM* memory = nullptr;
    Flags* flags = nullptr;
    Registers* registers = nullptr;

    static const std::string Nemonics[256];
};
#endif
