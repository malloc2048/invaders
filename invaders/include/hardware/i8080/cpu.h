#ifndef INVADERS_CPU_H
#define INVADERS_CPU_H

#include <map>
#include <vector>
#include "flags.h"
#include "memory.h"
#include "registers.h"
#include "instruction.h"
#include "common/config.h"
#include "hardware/constants.h"
#include "operations/operation.h"


namespace hardware {
    class CPU {
    public:
        explicit CPU(Memory& memory);
        ~CPU() = default;

        void step();
        void loadInstructionSet();
        void makeInstruction(const std::vector<std::string>& tokens);

        byte nextByte();

    public:
        Flags flags;
        Memory& memory;
        qword cycles = 0;
        common::Config cfg;
        Registers registers;
        qword instructionsProcessed = 0;
        std::map<byte, Instruction> instructions;
        std::map<std::string, Operation*> operationsMap;

        std::ofstream log;
        std::ofstream errorLog;
    };
}
#endif
