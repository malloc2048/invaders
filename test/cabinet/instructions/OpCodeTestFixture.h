#ifndef INVADERS_OPCODETESTFIXTURE_H
#define INVADERS_OPCODETESTFIXTURE_H

#include <gtest/gtest.h>
#include "cabinet/flags.h"
#include "cabinet/memory.h"
#include "cabinet/registers.h"

class OpCodeTestFixture: public testing::Test {
public:
    OpCodeTestFixture() = default;
    ~OpCodeTestFixture() override = default;

    void SetUp() override;

protected:
    cabinet::Flags flags;
    cabinet::Memory memory;
    Registers registers;
};
#endif
