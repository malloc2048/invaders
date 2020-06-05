#ifndef INVADERS_INTEL8080TESTFIXTURE_H
#define INVADERS_INTEL8080TESTFIXTURE_H

#include <sstream>
#include <gtest/gtest.h>
#include <machine/cpu/8080/intel8080.h>

class Intel8080TestFixture: public ::testing::Test {
public:
    Intel8080TestFixture();
    ~Intel8080TestFixture() override = default;

    void SetUp() override;
    void loadTestMemory(std::vector<uint8_t>& values);

protected:
    Memory ram;
    Flags flags;
    Registers regs;
    Intel8080 cpu;
    std::stringstream outputStream;
};
#endif
