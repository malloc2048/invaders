#ifndef EMULATOR_OPCODE_H
#define EMULATOR_OPCODE_H

#include <memory>
#include <iomanip>
#include <sstream>

#include "flags.h"
#include "registers.h"
#include "machine/memory/memory.h"

class OpCode {
public:
    OpCode() = default;
    ~OpCode() = default;

    // Returns the number of memory locations used in the instruction
    virtual int8_t Execute(uint8_t opcode, std::ostream& debug) = 0;
    virtual void Disassemble(std::ostream& out) = 0;

    void updateFlags(uint8_t value) ;
    static uint8_t calculateParity(uint8_t value);
    void updateCarry(uint8_t original, uint8_t updated) ;

protected:
    Memory* ram = nullptr;
    Flags* flags = nullptr;
    Registers* registers = nullptr;

    static std::string conditionStr[8];
    static std::string registerNames[8];
    static std::string registerPairNames[4];
};
#endif
