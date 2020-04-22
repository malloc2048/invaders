#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, ADD_B) {
    SetMemory(4, 0x80, 0x80, 0x80, 0x80);

    cpu.registers.bc.d8.highByte = 0x6f;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x6f);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.bc.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x70);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.bc.d8.highByte = 0xff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x6f);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);

    cpu.registers.bc.d8.highByte = 0x80;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xef);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x04);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}

TEST_F(InstructionTestFixture, ADD_C) {
    SetMemory(1, 0x81);

    cpu.registers.bc.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x01);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}

TEST_F(InstructionTestFixture, ADD_D) {
    SetMemory(1, 0x82);

    cpu.registers.de.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x01);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}

TEST_F(InstructionTestFixture, ADD_E) {
    SetMemory(1, 0x83);

    cpu.registers.de.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x01);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}

TEST_F(InstructionTestFixture, ADD_H) {
    SetMemory(1, 0x84);

    cpu.registers.hl.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x01);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}

TEST_F(InstructionTestFixture, ADD_L) {
    SetMemory(1, 0x85);

    cpu.registers.hl.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x01);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}

TEST_F(InstructionTestFixture, ADD_M) {
    SetMemory(2, 0x86, 0x01);

    cpu.registers.hl.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x01);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}

TEST_F(InstructionTestFixture, ADD_A) {
    SetMemory(1, 0x87);

    cpu.registers.a = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x02);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);
}
