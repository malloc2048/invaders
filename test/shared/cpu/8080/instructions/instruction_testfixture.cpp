#include <cstdarg>
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
        cpu.state.memory[index] = (uint8_t)value & 0xffu;
    }
}

void InstructionTestFixture::SetMem(uint64_t count, uint8_t values[]) const {
    for(size_t index = 0; index < count; index++) {
        cpu.state.memory[cpu.state.pc + index] = values[index];
    }
}

//void TestFixture::SetMemory(uint8_t value, size_t length, size_t start) const {
//    for(size_t index = 0; index < length; index++) {
//        cpu.state.memory[index] = value;
//    }
//}
