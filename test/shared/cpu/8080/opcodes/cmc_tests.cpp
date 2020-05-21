#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/cmc.h"

TEST_F(OpCodeTestFixture, CMC_Disassemble) {
    CMC instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0x3f));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "3f\tCMC");
}

TEST_F(OpCodeTestFixture, CMC_Execute_CarryZero) {
    CMC instruction(memory, flags, registers);

    flags->carry = 0x00;
    auto instructionSize = instruction.Execute(0x3f, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(flags->carry, 0x01);

    instructionSize = instruction.Execute(0x3f, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(flags->carry, 0x00);
}
