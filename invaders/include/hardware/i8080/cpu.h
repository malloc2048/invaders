#ifndef INVADERS_CPU_H
#define INVADERS_CPU_H

#include "flags.h"
#include "memory.h"
#include "registers.h"
#include "instruction.h"
#include "hardware/constants.h"
#include "operations/operation.h"

namespace hardware {
    class CPU {
    public:
        CPU();
        ~CPU() = default;

        void step();
        void loadInstructionSet();
        void makeInstruction(const std::vector<std::string>& tokens);

    protected:
        byte nextByte();

    private:
        Flags flags;
        Memory memory;
        qword cycles = 0;
        Registers registers;
        std::map<byte, Instruction> instructions;
        std::map<std::string, Operation*> operationsMap;
    };
}
#endif
