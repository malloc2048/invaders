#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, DCR_Test_) {
    std::vector<uint8_t> testMemory = {
        0x05, 0x0d, 0x15, 0x1d, 0x25, 0x2d, 0x35, 0x3d
    };
    loadTestMemory(testMemory);

    regs.a = 0xaa;
    regs.bc.d16 = 0x0000;
    regs.de.d16 = 0x0000;
    regs.hl.d16 = 0x2100;

    cpu.tick(); // DCR B
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x16);
    ASSERT_EQ(regs.pc.d16, 0x0001);
    ASSERT_EQ(regs.bc.d16, 0xff00);
    ASSERT_EQ(regs.de.d16, 0x0000);
    ASSERT_EQ(regs.hl.d16, 0x2100);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick(); // DCR C
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x16);
    ASSERT_EQ(regs.pc.d16, 0x0002);
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.de.d16, 0x0000);
    ASSERT_EQ(regs.hl.d16, 0x2100);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick(); // DCR D
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x16);
    ASSERT_EQ(regs.pc.d16, 0x0003);
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.de.d16, 0xff00);
    ASSERT_EQ(regs.hl.d16, 0x2100);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick(); // DCR E
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x16);
    ASSERT_EQ(regs.pc.d16, 0x0004);
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.hl.d16, 0x2100);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick(); // DCR H
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x00);
    ASSERT_EQ(regs.pc.d16, 0x0005);
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.hl.d16, 0x2000);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick(); // DCR L
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x16);
    ASSERT_EQ(regs.pc.d16, 0x0006);
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.hl.d16, 0x20ff);
    ASSERT_EQ(ram.read(regs.hl.d16), 0x00);

    cpu.tick(); // DCR M
    ASSERT_EQ(regs.a, 0xaa);
    ASSERT_EQ(flags.d8, 0x16);
    ASSERT_EQ(regs.pc.d16, 0x0007);
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.hl.d16, 0x20ff);
    ASSERT_EQ(ram.read(regs.hl.d16), 0xff);

    cpu.tick(); // DCR A
    ASSERT_EQ(regs.a, 0xa9);
    ASSERT_EQ(flags.d8, 0x06);
    ASSERT_EQ(regs.pc.d16, 0x0008);
    ASSERT_EQ(regs.bc.d16, 0xffff);
    ASSERT_EQ(regs.de.d16, 0xffff);
    ASSERT_EQ(regs.hl.d16, 0x20ff);
    ASSERT_EQ(ram.read(regs.hl.d16), 0xff);
}
