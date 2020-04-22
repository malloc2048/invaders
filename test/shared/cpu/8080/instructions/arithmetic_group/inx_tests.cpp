#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, INX_B) {
    SetMemory(3, 0x03, 0x03, 0x03);

    cpu.registers.bc.d16 = 0xfffe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d16 == 0xffff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}

TEST_F(InstructionTestFixture, INX_D) {
    SetMemory(3, 0x13, 0x13, 0x13);

    cpu.registers.de.d16 = 0xffff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d16 == 0x0001);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}

TEST_F(InstructionTestFixture, INX_H) {
    SetMemory(3, 0x23, 0x23, 0x23);

    cpu.registers.hl.d16 = 0xffff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0x0001);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}

TEST_F(InstructionTestFixture, INX_SP) {
    SetMemory(3, 0x33, 0x33, 0x33);

    cpu.registers.sp.d16 = 0xffff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.sp.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.sp.d16 == 0x0001);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}
