#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include <gtest/gtest.h>
#include "hardware/cabinet.h"

TEST(CabinetTest, cabinet) {
    hardware::Cabinet cabinet;

    cabinet.cpu.step();
    word address = 0x2000;
    cabinet.cpu.flags.interruptEnabled = true;
    cabinet.interrupt(address);

    ASSERT_EQ(address, cabinet.getPC());
    ASSERT_EQ(15, cabinet.getCycleCount());
    ASSERT_FALSE(cabinet.cpu.flags.interruptEnabled);

    cabinet.setCycleCount(0xaaaa);
    ASSERT_EQ(0xaaaa, cabinet.getCycleCount());

    cabinet.setAccumulator(0xaa);
    ASSERT_EQ(0xaa, cabinet.getAccumulator());

    cabinet.incrementPC(0x55);
    ASSERT_EQ(address + 0x55, cabinet.getPC());
}
