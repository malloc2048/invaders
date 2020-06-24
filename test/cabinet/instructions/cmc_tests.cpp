#include "OpCodeTestFixture.h"
#include "cabinet/instructions/cmc.h"

TEST_F(OpCodeTestFixture, CMC_Execute_CarryZero) {
    CMC instruction(flags, memory, registers);

    flags.carry = 0x00;
    instruction.Execute(0x3f);

    ASSERT_EQ(flags.carry, 0x01);

    instruction.Execute(0x3f);

    ASSERT_EQ(flags.carry, 0x00);
}
