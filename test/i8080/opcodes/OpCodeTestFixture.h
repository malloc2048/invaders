#ifndef INVADERS_OPCODETESTFIXTURE_H
#define INVADERS_OPCODETESTFIXTURE_H

#include <gtest/gtest.h>
#include "i8080/flags.h"
#include "memory/memory.h"
#include "i8080/registers.h"

class OpCodeTestFixture: public testing::Test {
public:
    OpCodeTestFixture() = default;
    ~OpCodeTestFixture() override = default;

    void SetUp() override;

protected:
    Flags flags;
    Memory memory;
    Registers registers;
};
#endif
