#include "instruction_testfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(InstructionTestFixture, JMP) {
    uint8_t testMemory[3] = {OPCODE_JMP, 0x06, 0x00};
    SetMem(3, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0006);
}

TEST_F(InstructionTestFixture, JNZ) {
    uint8_t testMemory[3] = {OPCODE_JNZ, 0x06, 0x00};
    SetMem(3, testMemory);

    cpu.state.cc.z = 0x00;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0003);

    cpu.state.pc = 0x00;
    cpu.state.cc.z = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0006);
}

TEST_F(InstructionTestFixture, RET) {
    uint8_t testMemory[3] = {OPCODE_NOP, OPCODE_NOP, OPCODE_RET};
    SetMem(3, testMemory);

    cpu.state.pc = 0x0002;
    cpu.state.sp = 0x0030;
    cpu.state.memory[0x30] = 0x00;
    cpu.state.memory[0x31] = 0x00;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0000);
    ASSERT_TRUE(cpu.state.sp == 0x0032);
}

TEST_F(InstructionTestFixture, CALL) {
    uint8_t testMemory[3] = {OPCODE_CALL, 0x06, 0x00};
    SetMem(3, testMemory);

    cpu.state.sp = 0x0032;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x0006);
    ASSERT_TRUE(cpu.state.sp == 0x0030);
    ASSERT_TRUE(cpu.state.memory[cpu.state.sp] == 0x03);
    ASSERT_TRUE(cpu.state.memory[cpu.state.sp + 1] == 0x00);
}
