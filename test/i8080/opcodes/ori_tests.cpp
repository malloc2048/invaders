#include "OpCodeTestFixture.h"
#include "i8080/opcodes/ori.h"

TEST_F(OpCodeTestFixture, ORI) {
    flags.carry = 1;
    registers.a = 0x55;
    flags.halfCarry = 1;
    ORI instruction(flags, memory, registers);

    instruction.Execute(0xe6);
    ASSERT_EQ(0x55, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}
