#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, DCX_B) {
    SetMemory(3, 0x0b, 0x0b, 0x0b);

    cpu.registers.bc.d16 = 0x0001;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d16 == 0xffff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}

TEST_F(InstructionTestFixture, DCX_D) {
    SetMemory(3, 0x1b, 0x1b, 0x1b);

    cpu.registers.de.d16 = 0x0001;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d16 == 0xffff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}

TEST_F(InstructionTestFixture, DCX_H) {
    SetMemory(3, 0x2b, 0x2b, 0x2b);

    cpu.registers.hl.d16 = 0x0001;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d16 == 0xffff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}

TEST_F(InstructionTestFixture, DCX_SP) {
    SetMemory(3, 0x3b, 0x3b, 0x3b);

    cpu.registers.sp.d16 = 0x0001;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.sp.d16 == 0x0000);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.sp.d16 == 0xffff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
}
