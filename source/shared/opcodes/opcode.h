#ifndef EMULATOR_OPCODE_H
#define EMULATOR_OPCODE_H

#include <cstdint>

struct OpCode {
    uint8_t code;
    uint8_t size;
    char* instruction;
    char* description;
};
#endif
