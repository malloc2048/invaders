#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, NOP_Test) {
    std::vector<uint8_t> testMemory = {
        0x00
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.a, 0x00);
    ASSERT_EQ(flags.d8, 0x00);
    ASSERT_EQ(regs.pc.d16, 0x0001);
}
