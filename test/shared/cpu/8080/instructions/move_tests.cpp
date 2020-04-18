#include "instruction_testfixture.h"
#include "cpu/8080/instructions/defines.h"

TEST_F(InstructionTestFixture, MVI_B) {
    uint8_t testMemory[3] = {OPCODE_MVI_B, 0xaa, 0x00};
    SetMem(3, testMemory);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.state.b == 0xaa);
    ASSERT_TRUE(cpu.state.pc == 0x02);
}
