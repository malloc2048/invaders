#ifndef INVADERS_OPCODE_H
#define INVADERS_OPCODE_H

#include <memory>
#include <iomanip>
#include <sstream>

#include "i8080/flags.h"
#include "memory/memory.h"
#include "i8080/registers.h"

class OpCode {
public:
    OpCode(Flags& flags, Memory& memory, Registers& registers);
    ~OpCode() = default;

    virtual void Execute(uint8_t opcode) = 0;

    void updateFlags(uint8_t value) ;
    static uint8_t calculateParity(uint8_t value);
    void updateCarry(uint8_t original, uint8_t updated) ;

protected:
    Flags& flags;
    Memory& memory;
    Registers& registers;

    static std::string conditionStr[8];
    static std::string registerNames[8];
    static std::string registerPairNames[4];
};
#endif
