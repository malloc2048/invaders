#include <cstdarg>
#include "common/config.h"
#include "instruction_testfixture.h"

InstructionTestFixture::InstructionTestFixture(): cpu(TestMemorySize) {}

void InstructionTestFixture::SetUp() {
    TraceOff();
}

void InstructionTestFixture::SetMemory(int length, ...) const {
    va_list valist;
    va_start(valist, length);

    for(int index = 0; index < length; index++) {
        int value = va_arg(valist, int);
        cpu.registers.memory[index] = (uint8_t)value & 0xffu;
    }
}
