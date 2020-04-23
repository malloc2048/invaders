#include "common/config.h"
#include "memorymaptestfixture.h"

TEST_F(MemoryMapTestFixture, AccumulatorReadWrite) {
    ASSERT_TRUE(mm.ReadA() == 0x00);
    mm.WriteA(0xff);
    ASSERT_TRUE(mm.ReadA() == 0xff);
}

TEST_F(MemoryMapTestFixture, BReadWrite) {
    ASSERT_TRUE(mm.ReadB() == 0x00);
    mm.WriteB(0xff);
    ASSERT_TRUE(mm.ReadB() == 0xff);
}

TEST_F(MemoryMapTestFixture, CReadWrite) {
    ASSERT_TRUE(mm.ReadC() == 0x00);
    mm.WriteC(0xff);
    ASSERT_TRUE(mm.ReadC() == 0xff);
}

TEST_F(MemoryMapTestFixture, DReadWrite) {
    ASSERT_TRUE(mm.ReadD() == 0x00);
    mm.WriteD(0xff);
    ASSERT_TRUE(mm.ReadD() == 0xff);
}

TEST_F(MemoryMapTestFixture, EReadWrite) {
    ASSERT_TRUE(mm.ReadE() == 0x00);
    mm.WriteE(0xff);
    ASSERT_TRUE(mm.ReadE() == 0xff);
}

TEST_F(MemoryMapTestFixture, HReadWrite) {
    ASSERT_TRUE(mm.ReadH() == 0x00);
    mm.WriteH(0xff);
    ASSERT_TRUE(mm.ReadH() == 0xff);
}

TEST_F(MemoryMapTestFixture, LReadWrite) {
    ASSERT_TRUE(mm.ReadL() == 0x00);
    mm.WriteL(0xff);
    ASSERT_TRUE(mm.ReadL() == 0xff);
}

TEST_F(MemoryMapTestFixture, RAMReadWrite) {
    ASSERT_TRUE(mm.Read(0x0000) == 0x00);
    mm.Write(0x0000, 0xff);
    ASSERT_TRUE(mm.Read(0x0000) == 0x00);

    mm.Write(0x2000, 0xff);
    ASSERT_TRUE(mm.Read(0x2000) == 0xff);
}
