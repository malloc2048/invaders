#ifndef EMULATOR_INSTRUCTION_TESTFIXTURE_H
#define EMULATOR_INSTRUCTION_TESTFIXTURE_H

#include <gtest/gtest.h>
#include "cpu/8080/state.h"
#include "cpu/8080/intel8080.h"
#include "cpu/8080/instructions/arithmetic_group.h"

class InstructionTestFixture: public ::testing::Test {
public:
    InstructionTestFixture();
    ~InstructionTestFixture() override = default;

    void SetUp() override;
    void SetMemory(int length, ...) const;
    void SetMem(uint64_t count, uint8_t values[]) const;

protected:
    Intel8080 cpu;
    const uint16_t TestMemorySize = 32;
};
#endif
