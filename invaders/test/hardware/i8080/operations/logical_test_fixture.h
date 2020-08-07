#ifndef INVADERS_ARITHMETIC_TEST_FIXTURE_H
#define INVADERS_ARITHMETIC_TEST_FIXTURE_H

#include <gtest/gtest.h>
#include "hardware/i8080/operations/logical.h"

class LogicalTestFixture: public testing::Test {
public:
    LogicalTestFixture() = default;
    ~LogicalTestFixture() override = default;

protected:
    hardware::Flags flags;
    hardware::Memory memory;
    hardware::Registers registers;
    hardware::Logical operation = hardware::Logical(flags, memory, registers);
};
#endif
