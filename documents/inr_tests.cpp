#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, INR_Test_) {
    std::vector<uint8_t> testMemory = {
        0x04, 0x0c, 0x14, 0x1c, 0x24, 0x2c, 0x34, 0x3c
    };
    loadTestMemory(testMemory);

    regs.a = 0xaa;
    regs.bc.d16 = 0xffff;
    regs.de.d16 = 0xffff;
    regs.hl.d16 = 0x2000;

    cpu.tick();
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x15);
    ASSERT_EQ(regs.pc.d16, 0x0001);
    ASSERT_EQ(regs.bc.d16, 0x00ff);
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.hl.d16, 0x2000);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x15);
    ASSERT_EQ(regs.pc.d16, 0x0002);
    ASSERT_EQ(regs.bc.d16, 0x0000);
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.hl.d16, 0x2000);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x15);
    ASSERT_EQ(regs.pc.d16, 0x0003);
    ASSERT_EQ(regs.bc.d16, 0x0000);
    ASSERT_EQ(regs.de.d16, 0x00ff);
    ASSERT_EQ(regs.hl.d16, 0x2000);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x15);
    ASSERT_EQ(regs.pc.d16, 0x0004);
    ASSERT_EQ(regs.bc.d16, 0x0000);
    ASSERT_EQ(regs.de.d16, 0x0000);
    ASSERT_EQ(regs.hl.d16, 0x2000);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x04);
    ASSERT_EQ(regs.pc.d16, 0x0005);
    ASSERT_EQ(regs.bc.d16, 0x0000);
    ASSERT_EQ(regs.de.d16, 0x0000);
    ASSERT_EQ(regs.hl.d16, 0x2100);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x00);
    ASSERT_EQ(regs.pc.d16, 0x0006);
    ASSERT_EQ(regs.bc.d16, 0x0000);
    ASSERT_EQ(regs.de.d16, 0x0000);
    ASSERT_EQ(regs.hl.d16, 0x2101);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x00);
    ASSERT_EQ(regs.pc.d16, 0x0007);
    ASSERT_EQ(regs.bc.d16, 0x0000);
    ASSERT_EQ(regs.de.d16, 0x0000);
    ASSERT_EQ(regs.hl.d16, 0x2101);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x01);

    cpu.tick();
    ASSERT_EQ(regs.a, 0xab);
    ASSERT_EQ(flags.d8, 0x02);
    ASSERT_EQ(regs.pc.d16, 0x0008);
    ASSERT_EQ(regs.bc.d16, 0x0000);
    ASSERT_EQ(regs.de.d16, 0x0000);
    ASSERT_EQ(regs.hl.d16, 0x2101);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x01);
}
