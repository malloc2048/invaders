#ifndef INVADERS_ARITHMETIC_TEST_FIXTURE_H
#define INVADERS_ARITHMETIC_TEST_FIXTURE_H

#include <gtest/gtest.h>
#include "hardware/i8080/operations/arithmetic.h"

class ArithmeticTestFixture: public testing::Test {
public:
    ArithmeticTestFixture() = default;
    ~ArithmeticTestFixture() override = default;

protected:
    hardware::Flags flags;
    hardware::Memory memory;
    hardware::Registers registers;
    hardware::Arithmetic arithmetic = hardware::Arithmetic(flags, memory, registers);
};
#endif
