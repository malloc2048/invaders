#include "OpCodeTestFixture.h"
#include "cabinet/instructions/adi.h"

TEST_F(OpCodeTestFixture, ADI_NoCarry) {
    ADI instruction(flags, memory, registers);
    registers.a = 0x01;

    instruction.Execute(0xc6);
    ASSERT_EQ(0x02, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ADIC_Carry) {
    registers.a = 0xff;
    ADI instruction(flags, memory, registers);

    instruction.Execute(0xc6);
    ASSERT_EQ(0x00, registers.a);
    ASSERT_EQ(0x01, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x01, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x01, flags.halfCarry);
}
