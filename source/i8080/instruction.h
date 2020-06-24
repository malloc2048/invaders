#ifndef INVADERS_INSTRUCTION_H
#define INVADERS_INSTRUCTION_H

#include <string>
#include <cstdint>
#include <functional>

class Instruction {
public:
    Instruction() = default;
    ~Instruction() = default;

    uint8_t size = 0x01;
    uint8_t cycles = 0x00;
    uint8_t opcode = 0x00;
    std::string mnemonic = "";
    std::function<void(uint8_t)> execute;
};
#endif
