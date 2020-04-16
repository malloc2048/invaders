#ifndef EMULATOR_ARITHMETICTESTFIXTURE_H
#define EMULATOR_ARITHMETICTESTFIXTURE_H

#include <gtest/gtest.h>
#include "cpu/8080/state.h"
#include "cpu/8080/intel8080.h"
#include "cpu/8080/instructions/arithmetic_group.h"

class ArithmeticTestFixture: public ::testing::Test {
public:
    ArithmeticTestFixture();
    void SetUp() override;
    void SetMemory(uint8_t value, size_t length, size_t start = 0) const;

protected:
    State8080 state;
};
#endif
