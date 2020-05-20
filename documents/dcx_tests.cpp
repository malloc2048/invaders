#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, DCX_B_Test) {
    std::vector<uint8_t> testMemory = {
        0x0b, 0x0b
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.bc.d16, 0xfffe);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}

TEST_F(Intel8080TestFixture, DCX_D_Test) {
    std::vector<uint8_t> testMemory = {
        0x1b, 0x1b
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.de.d16, 0xfffe);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}

TEST_F(Intel8080TestFixture, DCX_HL_Test) {
    std::vector<uint8_t> testMemory = {
        0x2b, 0x2b
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.hl.d16, 0xffff);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.hl.d16, 0xfffe);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}

TEST_F(Intel8080TestFixture, DCX_SP_Test) {
    std::vector<uint8_t> testMemory = {
        0x3b, 0x3b
    };
    loadTestMemory(testMemory);

    cpu.tick();
    ASSERT_EQ(regs.sp.d16, 0xffff);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    cpu.tick();
    ASSERT_EQ(regs.sp.d16, 0xfffe);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}
