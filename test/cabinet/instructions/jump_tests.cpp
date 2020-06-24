#include "OpCodeTestFixture.h"
#include "cabinet/instructions/jump.h"

TEST_F(OpCodeTestFixture, Jump_Execute) {
    Jump instruction(flags, memory, registers);
    instruction.Execute(0xc3);
    ASSERT_EQ(0x0201, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpNotZero) {
    flags.zero = 0x00;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xc2);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.zero = 0x01;
    instruction.Execute(0xc2);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpZero) {
    flags.zero = 0x01;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xca);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.zero = 0x00;
    instruction.Execute(0xca);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpNoCarry) {
    flags.carry = 0x00;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xd2);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.carry = 0x01;
    instruction.Execute(0xd2);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpCarry) {
    flags.carry = 0x01;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xda);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.carry = 0x00;
    instruction.Execute(0xda);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpParityOdd) {
    flags.parity = 0x00;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xe2);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.parity = 0x01;
    instruction.Execute(0xe2);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpParityEven) {
    flags.parity = 0x01;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xea);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.parity = 0x00;
    instruction.Execute(0xea);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpPlus) {
    flags.sign = 0x00;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xf2);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.sign = 0x01;
    instruction.Execute(0xf2);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, JumpMinus) {
    flags.sign = 0x01;
    Jump instruction(flags, memory, registers);

    instruction.Execute(0xfa);
    ASSERT_EQ(0x0201, registers.pc.d16);

    flags.sign = 0x00;
    instruction.Execute(0xfa);
    ASSERT_EQ(0x0201 + 2, registers.pc.d16);
}
