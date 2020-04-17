#include "arithmetictestfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(ArithmeticTestFixture, INX_D) {
    SetMemory(OPCODE_INX_D, 8);

    cpu.state.d = 0xaa;
    cpu.state.e = 0x55;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.d == 0xaa);
    ASSERT_TRUE(cpu.state.e == 0x56);
    ASSERT_TRUE(cpu.state.pc == 0x01);

    cpu.state.d = 0x00;
    cpu.state.e = 0xff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.d == 0x01);
    ASSERT_TRUE(cpu.state.e == 0x00);
    ASSERT_TRUE(cpu.state.pc == 0x02);
}

TEST_F(ArithmeticTestFixture, INX_H) {
    SetMemory(OPCODE_INX_H, 8);

    cpu.state.h = 0xaa;
    cpu.state.l = 0x55;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0xaa);
    ASSERT_TRUE(cpu.state.l == 0x56);
    ASSERT_TRUE(cpu.state.pc == 0x01);

    cpu.state.h = 0x00;
    cpu.state.l = 0xff;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.h == 0x01);
    ASSERT_TRUE(cpu.state.l == 0x00);
    ASSERT_TRUE(cpu.state.pc == 0x02);
}
