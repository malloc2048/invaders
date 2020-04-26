#include <gtest/gtest.h>
#include <machine/ram/ram.h>

TEST(RamTest, ReadWriteRom) {
    RAM memory;

    ASSERT_EQ(0, memory.read(0x0000));
    ASSERT_FALSE(memory.write(0x0000, 0xff));
    ASSERT_EQ(0x00, memory.read(0x0000));
}

TEST(RamTest, ReadWrite) {
    RAM memory;

    ASSERT_EQ(0, memory.read(0x2000));
    ASSERT_TRUE(memory.write(0x2000, 0xff));
    ASSERT_EQ(0xff, memory.read(0x2000));
}
