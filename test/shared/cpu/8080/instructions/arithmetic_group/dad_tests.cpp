#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, DAD_B) {
    SetMemory(2, 0x09, 0x09);

    cpu.registers.bc.d16 = 0xff00;
    cpu.registers.hl.d16 = 0x0000;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0xff00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0001);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.bc.d16 = 0x01ff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0x00ff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0002);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, DAD_D) {
    SetMemory(2, 0x19, 0x19);

    cpu.registers.de.d16 = 0xff00;
    cpu.registers.hl.d16 = 0x0000;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0xff00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0001);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.de.d16 = 0x01ff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0x00ff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0002);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, DAD_H) {
    SetMemory(2, 0x29, 0x29);

    cpu.registers.hl.d16 = 0x0001;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0x0002);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0001);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.hl.d16 = 0xffff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0xfffe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0002);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, DAD_SP) {
    SetMemory(2, 0x39, 0x39);

    cpu.registers.sp.d16 = 0xff00;
    cpu.registers.hl.d16 = 0x0000;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0xff00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0001);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.sp.d16 = 0x01ff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0x00ff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x0002);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}
