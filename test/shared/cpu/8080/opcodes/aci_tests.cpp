#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, ACI_Test) {
    std::vector<uint8_t> testMemory = {
        0xce, 0xff, 0xce, 0x01, 0xce, 0x01
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xff);
    ASSERT_EQ(flags.d8, 0x16);
    ASSERT_EQ(regs.pc.d16, 0x0002);

    cpu.tick();
    ASSERT_EQ(regs.a, 0x00);
    ASSERT_EQ(flags.d8, 0x1d);
    ASSERT_EQ(regs.pc.d16, 0x0004);

    cpu.tick();
    ASSERT_EQ(regs.a, 0x02);
    ASSERT_EQ(flags.d8, 0x00);
    ASSERT_EQ(regs.pc.d16, 0x0006);
}
