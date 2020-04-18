#include "instruction_testfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(InstructionTestFixture, IN) {
    uint8_t testMemory[3] = {OPCODE_IN, 0x03, 0x00};
    SetMem(3, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.pc == 0x02);
    ASSERT_TRUE(cpu.state.a == cpu.state.shift);
}
