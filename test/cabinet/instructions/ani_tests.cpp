#include "OpCodeTestFixture.h"
#include "cabinet/instructions/ani.h"

TEST_F(OpCodeTestFixture, ANI) {
    flags.carry = 1;
    registers.a = 0x55;
    flags.halfCarry = 1;
    ANI instruction(flags, memory, registers);

    instruction.Execute(0xe6);
    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}
