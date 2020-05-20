#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, ADI_Test) {
    std::vector<uint8_t> testMemory = {
        0xc6, 0xff, 0xc6, 0x01, 0xc6, 0x01
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
    ASSERT_EQ(regs.a, 0x01);
    ASSERT_EQ(flags.d8, 0x00);
    ASSERT_EQ(regs.pc.d16, 0x0006);
}
