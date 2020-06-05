#include "OpCodeTestFixture.h"
#include "i8080/opcodes/aci.h"

TEST_F(OpCodeTestFixture, ACI_Execute_CarryZero) {
    ACI instruction(flags, memory, registers);
    instruction.Execute(0xCE);
    ASSERT_EQ(registers.a, 0x01);
}

TEST_F(OpCodeTestFixture, ACI_Execute_CarrySet) {
    ACI instruction(flags, memory, registers);
    flags.carry = 1;
    instruction.Execute(0xCE);
    ASSERT_EQ(registers.a, 0x02);
}

TEST_F(OpCodeTestFixture, ACI_Execute_CarryFlagSet) {
    ACI instruction(flags, memory, registers);
    registers.a = 0xff;
    instruction.Execute(0xCE);
    ASSERT_EQ(registers.a, 0x00);
    ASSERT_EQ(0x01, flags.carry);
    ASSERT_EQ(0x01, flags.zero);
}

TEST_F(OpCodeTestFixture, ACI_Execute_SignFlagSet) {
    ACI instruction(flags, memory, registers);
    registers.a = 0x7f;
    instruction.Execute(0xCE);
    ASSERT_EQ(registers.a, 0x80);
    ASSERT_EQ(0x01, flags.sign);
}
