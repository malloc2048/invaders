#include <gtest/gtest.h>
#include "hardware/i8080/cpu.h"

TEST(CPUTest, LoadInstructionSet) {
    hardware::CPU cpu;
    cpu.loadInstructionSet();
}
