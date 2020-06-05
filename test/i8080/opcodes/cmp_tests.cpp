#include "OpCodeTestFixture.h"
#include "i8080/opcodes/cmp.h"

TEST_F(OpCodeTestFixture, CMP_B) {
    CMP instruction(flags, memory, registers);

    registers.a = 0xaa;
    registers.bc.bytes.high = 0xaa;
    instruction.Execute(0xb8);


    ASSERT_EQ(0xaa, registers.a);

    ASSERT_EQ(flags.sign, 0x00);
    ASSERT_EQ(flags.zero, 0x01);
    ASSERT_EQ(flags.carry, 0x00);
    ASSERT_EQ(flags.parity, 0x01);
    ASSERT_EQ(flags.halfCarry, 0x00);
}

TEST_F(OpCodeTestFixture, CMP_C) {
    CMP instruction(flags, memory, registers);

    registers.a = 0xaa;
    registers.bc.bytes.low = 0x00;
    instruction.Execute(0xb9);


    ASSERT_EQ(0xaa, registers.a);

    ASSERT_EQ(flags.sign, 0x01);
    ASSERT_EQ(flags.zero, 0x00);
    ASSERT_EQ(flags.carry, 0x00);
    ASSERT_EQ(flags.parity, 0x01);
    ASSERT_EQ(flags.halfCarry, 0x00);
}

TEST_F(OpCodeTestFixture, CMP_D) {
    CMP instruction(flags, memory, registers);

    registers.a = 0xaa;
    registers.de.bytes.high = 0x55;
    instruction.Execute(0xba);


    ASSERT_EQ(0xaa, registers.a);

    ASSERT_EQ(flags.sign, 0x00);
    ASSERT_EQ(flags.zero, 0x00);
    ASSERT_EQ(flags.carry, 0x00);
    ASSERT_EQ(flags.parity, 0x01);
    ASSERT_EQ(flags.halfCarry, 0x00);
}

TEST_F(OpCodeTestFixture, CMP_E) {
    CMP instruction(flags, memory, registers);

    registers.a = 0xaa;
    registers.de.bytes.low = 0xff;
    instruction.Execute(0xbb);


    ASSERT_EQ(0xaa, registers.a);

    ASSERT_EQ(flags.sign, 0x01);
    ASSERT_EQ(flags.zero, 0x00);
    ASSERT_EQ(flags.carry, 0x01);
    ASSERT_EQ(flags.parity, 0x00);
    ASSERT_EQ(flags.halfCarry, 0x01);
}

TEST_F(OpCodeTestFixture, CMP_H) {
    CMP instruction(flags, memory, registers);

    registers.a = 0xaa;
    registers.hl.bytes.high = 0xff;
    instruction.Execute(0xbc);


    ASSERT_EQ(0xaa, registers.a);

    ASSERT_EQ(flags.sign, 0x01);
    ASSERT_EQ(flags.zero, 0x00);
    ASSERT_EQ(flags.carry, 0x01);
    ASSERT_EQ(flags.parity, 0x00);
    ASSERT_EQ(flags.halfCarry, 0x01);
}