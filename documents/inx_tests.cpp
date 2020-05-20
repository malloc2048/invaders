#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, INX_B_Test) {
    std::vector<uint8_t> testMemory = {
        0x03, 0x03
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.bc.d16, 0x0001);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.bc.d16, 0x0002);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}

TEST_F(Intel8080TestFixture, INX_D_Test) {
    std::vector<uint8_t> testMemory = {
        0x13, 0x13
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.de.d16, 0x0001);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.de.d16, 0x0002);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}

TEST_F(Intel8080TestFixture, INX_HL_Test) {
    std::vector<uint8_t> testMemory = {
        0x23, 0x23
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.hl.d16, 0x0001);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.hl.d16, 0x0002);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}

TEST_F(Intel8080TestFixture, INX_SP_Test) {
    std::vector<uint8_t> testMemory = {
        0x33, 0x33
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.sp.d16, 0x0001);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.sp.d16, 0x0002);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}
