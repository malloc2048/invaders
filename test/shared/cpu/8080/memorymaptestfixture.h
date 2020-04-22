#ifndef EMULATOR_MEMORYMAPTESTFIXTURE_H
#define EMULATOR_MEMORYMAPTESTFIXTURE_H

#include <gtest/gtest.h>
#include "cpu/8080/memorymap.h"

class MemoryMapTestFixture: public ::testing::Test {
public:
    MemoryMapTestFixture() = default;
    ~MemoryMapTestFixture() override = default;

    void SetUp() override;
    void SetMemory(int length, ...) const;

protected:
    MemoryMap mm = {};
};
#endif
