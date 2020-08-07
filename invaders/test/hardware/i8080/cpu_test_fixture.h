#ifndef INVADERS_CPU_TEST_FIXTURE_H
#define INVADERS_CPU_TEST_FIXTURE_H

#include <gtest/gtest.h>
#include "hardware/i8080/cpu.h"

class CpuTestFixture: public testing::Test {
public:
    CpuTestFixture() : cpu(memory){}
    ~CpuTestFixture() override = default;

protected:
    hardware::CPU cpu;
    hardware::Memory memory;
};
#endif
