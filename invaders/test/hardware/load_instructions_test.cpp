#include <gtest/gtest.h>
#include "hardware/i8080/cpu.h"

TEST(CPUTest, LoadInstructionSet) {
    hardware::Memory memory;
    hardware::CPU cpu(memory);
    cpu.loadInstructionSet();
}
