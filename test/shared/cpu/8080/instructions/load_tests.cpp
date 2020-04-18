#include "instruction_testfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(InstructionTestFixture, LXI_B) {
    uint8_t testMemory[3] = {OPCODE_LXI_B, 0x55, 0xaa};
    SetMem(3, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0003);
    ASSERT_TRUE(cpu.state.b == 0xaa);
    ASSERT_TRUE(cpu.state.c == 0x55);
}

TEST_F(InstructionTestFixture, LXI_D) {
    uint8_t testMemory[3] = {OPCODE_LXI_D, 0x55, 0xaa};
    SetMem(3, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0003);
    ASSERT_TRUE(cpu.state.d == 0xaa);
    ASSERT_TRUE(cpu.state.e == 0x55);
}

TEST_F(InstructionTestFixture, LXI_H) {
    uint8_t testMemory[3] = {OPCODE_LXI_H, 0x55, 0xaa};
    SetMem(3, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0003);
    ASSERT_TRUE(cpu.state.h == 0xaa);
    ASSERT_TRUE(cpu.state.l == 0x55);
}

TEST_F(InstructionTestFixture, LXI_SP) {
    uint8_t testMemory[3] = {OPCODE_LXI_SP, 0x55, 0xaa};
    SetMem(3, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0003);
    ASSERT_TRUE(cpu.state.sp == 0xaa55);
}

TEST_F(InstructionTestFixture, LDA) {
    uint8_t testMemory[4] = {OPCODE_LDA, 0x03, 0x00, 0xaa};
    SetMem(4, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0003);
    ASSERT_TRUE(cpu.state.a == 0xaa);
}

TEST_F(InstructionTestFixture, LDAX_B) {
    uint8_t testMemory[4] = {OPCODE_LDAX_B, 0x03, 0x00, 0xaa};
    SetMem(4, testMemory);

    cpu.state.b = 0x00;
    cpu.state.c = 0x03;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0001);
    ASSERT_TRUE(cpu.state.a == 0xaa);
}

TEST_F(InstructionTestFixture, LDAX_D) {
    uint8_t testMemory[4] = {OPCODE_LDAX_D, 0x03, 0x00, 0xaa};
    SetMem(4, testMemory);

    cpu.state.d = 0x00;
    cpu.state.e = 0x03;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0001);
    ASSERT_TRUE(cpu.state.a == 0xaa);
}

TEST_F(InstructionTestFixture, XCHG) {
    uint8_t testMemory[4] = {OPCODE_XCHG, 0x03, 0x00, 0xaa};
    SetMem(4, testMemory);

    cpu.state.h = 0x00;
    cpu.state.l = 0xff;
    cpu.state.d = 0xaa;
    cpu.state.e = 0x55;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0001);
    ASSERT_TRUE(cpu.state.h == 0xaa);
    ASSERT_TRUE(cpu.state.l == 0x55);
    ASSERT_TRUE(cpu.state.d == 0x00);
    ASSERT_TRUE(cpu.state.e == 0xff);
}
