#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, ADI) {
    SetMemory(4, 0xc6, 0xff, 0xc6, 0x01);

    cpu.registers.a = 0x00;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x04);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}
