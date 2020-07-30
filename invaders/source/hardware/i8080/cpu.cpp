#include <regex>
#include <fstream>
#include "hardware/i8080/cpu.h"
#include "hardware/i8080/operations/arithmetic.h"

hardware::CPU::CPU() {
    operationsMap = {
        {"arithmetic", new Arithmetic(flags, memory, registers)}
    };
}

void hardware::CPU::step() {
    auto opcode = nextByte();

    if(instructions.find(opcode) != instructions.end()) {
        cycles += instructions[opcode].cycles;
        instructions[opcode].operation->execute(opcode);
    }
}

#include <iostream>
void hardware::CPU::loadInstructionSet() {
    std::string line;
    std::ifstream instruction_set(InstructionSetCSV());
    while (std::getline(instruction_set, line)) {
        auto const re = std::regex{R"(:+)"};
        auto const tokens = std::vector<std::string>(
            std::sregex_token_iterator{begin(line), end(line), re, -1},
            std::sregex_token_iterator{}
        );

        if(tokens.size() == 5) {
            makeInstruction(tokens);
        }
    }
    instruction_set.close();
}

void hardware::CPU::makeInstruction(const std::vector<std::string> &tokens) {
    try {
        auto opcode = std::stoi(tokens[0], 0, 16);
        auto mnemonic = tokens[1];

        Operation *operation = nullptr;
        if (operationsMap.find(tokens[3]) != operationsMap.end()) {
            operation = operationsMap[tokens[3]];
        }

        instructions.insert(
            std::pair<byte, Instruction>(
                opcode, Instruction{
                    .opcode =  byte(opcode),
                    .mnemonic =  mnemonic,
                    .operation = operation,
                }));
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

byte hardware::CPU::nextByte() {
    return memory.read_byte(registers.program_counter++);
}
