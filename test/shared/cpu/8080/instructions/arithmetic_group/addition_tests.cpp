#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, AddB) {
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

TEST_F(InstructionTestFixture, AddC) {
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

TEST_F(InstructionTestFixture, AddD) {
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

TEST_F(InstructionTestFixture, AddE) {
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

TEST_F(InstructionTestFixture, AddH) {
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

TEST_F(InstructionTestFixture, AddL) {
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

TEST_F(InstructionTestFixture, AddM) {
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

TEST_F(InstructionTestFixture, AddA) {
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
