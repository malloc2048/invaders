#ifndef INVADERS_BRANCHING_TEST_FIXTURE_H
#define INVADERS_BRANCHING_TEST_FIXTURE_H

#include <gtest/gtest.h>
#include "hardware/i8080/operations/branching.h"

class BranchingTestFixture: public testing::Test {
public:
    BranchingTestFixture() = default;
    ~BranchingTestFixture() override = default;

protected:
    hardware::Flags flags;
    hardware::Memory memory;
    hardware::Registers registers;
    hardware::Branching branching = hardware::Branching(flags, memory, registers);
};
#endif
