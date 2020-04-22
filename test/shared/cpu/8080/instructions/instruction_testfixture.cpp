#include <cstdarg>
#include "common/config.h"
#include "instruction_testfixture.h"

InstructionTestFixture::InstructionTestFixture(): cpu() {}

void InstructionTestFixture::SetUp() {
    TraceOff();
}

void InstructionTestFixture::SetMemory(int length, ...) const {
    va_list vaList;
    va_start(vaList, length);

    for(int index = 0; index < length; index++) {
        int value = va_arg(vaList, int);
        cpu.registers.memory[index] = (uint8_t)value & 0xffu;
    }
}
