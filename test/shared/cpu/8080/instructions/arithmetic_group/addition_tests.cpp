#include "arithmetictestfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(ArithmeticTestFixture, DAD_B) {
    SetMemory(OPCODE_DAD_B, 8);

    cpu.state.b = 0xff;
    cpu.state.c = 0xff;
    cpu.state.h = 0x00;
    cpu.state.l = 0x00;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0xff);
    ASSERT_TRUE(cpu.state.l == 0xff);
    ASSERT_TRUE(cpu.state.pc == 0x01);
    ASSERT_TRUE(cpu.state.cc.cy == 0x00);

    cpu.state.b = 0x00;
    cpu.state.c = 0x01;
    cpu.state.h = 0xff;
    cpu.state.l = 0xff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0x00);
    ASSERT_TRUE(cpu.state.l == 0x00);
    ASSERT_TRUE(cpu.state.pc == 0x02);
    ASSERT_TRUE(cpu.state.cc.cy == 0x01);
}

TEST_F(ArithmeticTestFixture, DAD_D) {
    SetMemory(OPCODE_DAD_D, 8);

    cpu.state.d = 0xff;
    cpu.state.e = 0xff;
    cpu.state.h = 0x00;
    cpu.state.l = 0x00;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0xff);
    ASSERT_TRUE(cpu.state.l == 0xff);
    ASSERT_TRUE(cpu.state.pc == 0x01);
    ASSERT_TRUE(cpu.state.cc.cy == 0x00);

    cpu.state.d = 0x00;
    cpu.state.e = 0x01;
    cpu.state.h = 0xff;
    cpu.state.l = 0xff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0x00);
    ASSERT_TRUE(cpu.state.l == 0x00);
    ASSERT_TRUE(cpu.state.pc == 0x02);
    ASSERT_TRUE(cpu.state.cc.cy == 0x01);
}

TEST_F(ArithmeticTestFixture, DAD_H) {
    SetMemory(OPCODE_DAD_H, 8);

    cpu.state.h = 0x00;
    cpu.state.l = 0x02;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0x00);
    ASSERT_TRUE(cpu.state.l == 0x04);
    ASSERT_TRUE(cpu.state.pc == 0x01);
    ASSERT_TRUE(cpu.state.cc.cy == 0x00);

    cpu.state.h = 0xff;
    cpu.state.l = 0xff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0xff);
    ASSERT_TRUE(cpu.state.l == 0xfe);
    ASSERT_TRUE(cpu.state.pc == 0x02);
    ASSERT_TRUE(cpu.state.cc.cy == 0x01);
}
