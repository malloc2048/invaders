#include "arithmetictestfixture.h"

TEST_F(ArithmeticTestFixture, DCR_B) {
    SetMemory(OPCODE_DCR_B, 8);

    state.b = 0x01;
    Emulate8080(&state);
    ASSERT_TRUE(state.b == 0x00);
    ASSERT_TRUE(state.pc == 0x01);
    ASSERT_TRUE(state.cc.z == 0x01);
    ASSERT_TRUE(state.cc.s == 0x00);
    ASSERT_TRUE(state.cc.p == 0x00);
    ASSERT_TRUE(state.cc.ac == 0x00);

    Emulate8080(&state);
    ASSERT_TRUE(state.b == 0xff);
    ASSERT_TRUE(state.pc == 0x02);
    ASSERT_TRUE(state.cc.z == 0x00);
    ASSERT_TRUE(state.cc.s == 0x01);
    ASSERT_TRUE(state.cc.p == 0x00);
    ASSERT_TRUE(state.cc.ac == 0x01);

    Emulate8080(&state);
    ASSERT_TRUE(state.b == 0xfe);
    ASSERT_TRUE(state.pc == 0x03);
    ASSERT_TRUE(state.cc.z == 0x00);
    ASSERT_TRUE(state.cc.s == 0x01);
    ASSERT_TRUE(state.cc.p == 0x01);
    ASSERT_TRUE(state.cc.ac == 0x00);
}
