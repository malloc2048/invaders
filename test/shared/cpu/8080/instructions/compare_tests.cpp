#include "instruction_testfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(InstructionTestFixture, CPI) {
    uint8_t testMemory[6] = {OPCODE_CPI, 0x00, OPCODE_CPI, 0x01, OPCODE_CPI, 0x01};
    SetMem(6, testMemory);

    cpu.state.a = 0x00;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x02);
    ASSERT_TRUE(cpu.state.cc.z == 0x01);
    ASSERT_TRUE(cpu.state.cc.s == 0x00);
    ASSERT_TRUE(cpu.state.cc.p == 0x00);
    ASSERT_TRUE(cpu.state.cc.cy == 0x00);
    ASSERT_TRUE(cpu.state.cc.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x04);
    ASSERT_TRUE(cpu.state.cc.z == 0x00);
    ASSERT_TRUE(cpu.state.cc.s == 0x01);
    ASSERT_TRUE(cpu.state.cc.p == 0x00);
    ASSERT_TRUE(cpu.state.cc.cy == 0x01);
    ASSERT_TRUE(cpu.state.cc.ac == 0x00);

    cpu.state.a = 0x03;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x06);
    ASSERT_TRUE(cpu.state.cc.z == 0x00);
    ASSERT_TRUE(cpu.state.cc.s == 0x00);
    ASSERT_TRUE(cpu.state.cc.p == 0x01);
    ASSERT_TRUE(cpu.state.cc.cy == 0x00);
    ASSERT_TRUE(cpu.state.cc.ac == 0x00);
}
