#include "arithmetictestfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(ArithmeticTestFixture, DCR_B) {
    SetMemory(OPCODE_DCR_B, 8);

    cpu.state.b = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.b == 0x00);
    ASSERT_TRUE(cpu.state.pc == 0x01);
    ASSERT_TRUE(cpu.state.cc.z == 0x01);
    ASSERT_TRUE(cpu.state.cc.s == 0x00);
    ASSERT_TRUE(cpu.state.cc.p == 0x00);
    ASSERT_TRUE(cpu.state.cc.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.b == 0xff);
    ASSERT_TRUE(cpu.state.pc == 0x02);
    ASSERT_TRUE(cpu.state.cc.z == 0x00);
    ASSERT_TRUE(cpu.state.cc.s == 0x01);
    ASSERT_TRUE(cpu.state.cc.p == 0x00);
    ASSERT_TRUE(cpu.state.cc.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.b == 0xfe);
    ASSERT_TRUE(cpu.state.pc == 0x03);
    ASSERT_TRUE(cpu.state.cc.z == 0x00);
    ASSERT_TRUE(cpu.state.cc.s == 0x01);
    ASSERT_TRUE(cpu.state.cc.p == 0x01);
    ASSERT_TRUE(cpu.state.cc.ac == 0x00);
}

TEST_F(ArithmeticTestFixture, DCR_C) {
    SetMemory(OPCODE_DCR_C, 8);

    cpu.state.c = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.c == 0x00);
    ASSERT_TRUE(cpu.state.pc == 0x01);
    ASSERT_TRUE(cpu.state.cc.z == 0x01);
    ASSERT_TRUE(cpu.state.cc.s == 0x00);
    ASSERT_TRUE(cpu.state.cc.p == 0x00);
    ASSERT_TRUE(cpu.state.cc.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.c == 0xff);
    ASSERT_TRUE(cpu.state.pc == 0x02);
    ASSERT_TRUE(cpu.state.cc.z == 0x00);
    ASSERT_TRUE(cpu.state.cc.s == 0x01);
    ASSERT_TRUE(cpu.state.cc.p == 0x00);
    ASSERT_TRUE(cpu.state.cc.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.c == 0xfe);
    ASSERT_TRUE(cpu.state.pc == 0x03);
    ASSERT_TRUE(cpu.state.cc.z == 0x00);
    ASSERT_TRUE(cpu.state.cc.s == 0x01);
    ASSERT_TRUE(cpu.state.cc.p == 0x01);
    ASSERT_TRUE(cpu.state.cc.ac == 0x00);
}
