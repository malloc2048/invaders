#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, ADC_B) {
    SetMemory(4, 0x88, 0x88, 0x88, 0x88);

    cpu.registers.a = 0x02;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.registers.bc.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x04);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.bc.d8.highByte = 0xfb;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.bc.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, ADC_C) {
    SetMemory(3, 0x89, 0x89, 0x89);

    cpu.registers.a = 0x02;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.registers.bc.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x04);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.bc.d8.lowByte = 0xfb;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.bc.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, ADC_D) {
    SetMemory(3, 0x8a, 0x8a, 0x8a);

    cpu.registers.a = 0x02;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.registers.de.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x04);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.de.d8.highByte = 0xfb;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.de.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, ADC_E) {
    SetMemory(3, 0x8b, 0x8b, 0x8b);

    cpu.registers.a = 0x02;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.registers.de.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x04);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.de.d8.lowByte = 0xfb;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.de.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, ADC_H) {
    SetMemory(3, 0x8c, 0x8c, 0x8c);

    cpu.registers.a = 0x02;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.registers.hl.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x04);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.hl.d8.highByte = 0xfb;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.hl.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, ADC_L) {
    SetMemory(3, 0x8d, 0x8d, 0x8d);

    cpu.registers.a = 0x02;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.registers.hl.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x04);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.hl.d8.lowByte = 0xfb;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.hl.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, ADC_M) {
    SetMemory(6, 0x8e, 0x8e, 0x8e, 0x01, 0xfb, 0x01);

    cpu.registers.a = 0x02;
    cpu.registers.hl.d16 = 0x03;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x04);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.hl.d16 += 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.hl.d16 += 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}

TEST_F(InstructionTestFixture, ADC_A) {
    SetMemory(3, 0x8f, 0x8f, 0x8f);

    cpu.registers.a = 0x02;
    cpu.registers.psw.flags.cy = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x05);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x00);

    cpu.registers.a = 0xff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.cy == 0x01);
}
