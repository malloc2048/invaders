#ifndef INVADERS_OPCODETESTFIXTURE_H
#define INVADERS_OPCODETESTFIXTURE_H

#include <gtest/gtest.h>
#include "machine/memory/memory.h"
#include "machine/cpu/8080/flags.h"
#include "machine/cpu/8080/registers.h"

class OpCodeTestFixture: public testing::Test {
public:
    OpCodeTestFixture();
    ~OpCodeTestFixture() override;

    void SetUp() override;

protected:
    Flags* flags;
    Memory* memory;
    Registers* registers;

    std::stringstream out;
};
#endif
