#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, LXI_B_Test) {
    std::vector<uint8_t> testMemory = {
        0x01, 0x55, 0xaa
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.bc.bytes.low, 0x55);
    ASSERT_EQ(regs.bc.bytes.high, 0xaa);
    ASSERT_EQ(regs.pc.d16, 0x0003);
}

TEST_F(Intel8080TestFixture, LXI_D_Test) {
    std::vector<uint8_t> testMemory = {
        0x11, 0x55, 0xaa
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.de.bytes.low, 0x55);
    ASSERT_EQ(regs.de.bytes.high, 0xaa);
    ASSERT_EQ(regs.pc.d16, 0x0003);
}

TEST_F(Intel8080TestFixture, LXI_HL_Test) {
    std::vector<uint8_t> testMemory = {
        0x21, 0x55, 0xaa
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.hl.bytes.low, 0x55);
    ASSERT_EQ(regs.hl.bytes.high, 0xaa);
    ASSERT_EQ(regs.pc.d16, 0x0003);
}

TEST_F(Intel8080TestFixture, LXI_SP_Test) {
    std::vector<uint8_t> testMemory = {
        0x31, 0x55, 0xaa
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.sp.bytes.low, 0x55);
    ASSERT_EQ(regs.sp.bytes.high, 0xaa);
    ASSERT_EQ(regs.pc.d16, 0x0003);
}
