#ifndef EMULATOR_INSTRUCTION_TESTFIXTURE_H
#define EMULATOR_INSTRUCTION_TESTFIXTURE_H

#include <gtest/gtest.h>
#include "cpu/8080/intel8080.h"

class InstructionTestFixture: public ::testing::Test {
public:
    InstructionTestFixture();
    ~InstructionTestFixture() override = default;

    void SetUp() override;
    void SetMemory(int length, ...) const;

protected:
    Intel8080 cpu;
};
#endif
