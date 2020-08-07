#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "cpu_test_fixture.h"

TEST_F(CpuTestFixture, step) {
    cpu.loadInstructionSet();
    cpu.step();
    ASSERT_EQ(0x0001, cpu.registers.program_counter);
}
