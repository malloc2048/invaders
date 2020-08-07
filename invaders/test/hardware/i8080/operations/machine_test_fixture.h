#ifndef INVADERS_ARITHMETIC_TEST_FIXTURE_H
#define INVADERS_ARITHMETIC_TEST_FIXTURE_H

#include <gtest/gtest.h>
#include "hardware/i8080/operations/machine.h"

class MachineTestFixture: public testing::Test {
public:
    MachineTestFixture() = default;
    ~MachineTestFixture() override = default;

protected:
    hardware::Flags flags;
    hardware::Memory memory;
    hardware::Registers registers;
    hardware::Machine operation = hardware::Machine(flags, memory, registers);
};
#endif
