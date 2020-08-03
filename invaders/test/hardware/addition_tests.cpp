#include "arithmetic_test_fixture.h"

TEST_F(ArithmeticTestFixture, add) {
    registers.b = 0x56;
    registers.c = 0x02;
    registers.d = 0x03;
    registers.e = 0x04;
    registers.h = 0x50;
    registers.l = 0x06;
    registers.accumulator = 0xaa;
    memory.write(0x5006, 0xff);

    arithmetic.execute(0x80);
    ASSERT_FALSE(flags.sign);
    ASSERT_TRUE(flags.zero);
    ASSERT_TRUE(flags.carry);
    ASSERT_TRUE(flags.parity);
    ASSERT_TRUE(flags.half_carry);
    ASSERT_EQ(0x00, registers.accumulator);

    arithmetic.execute(0x81);
    ASSERT_FALSE(flags.sign);
    ASSERT_FALSE(flags.zero);
    ASSERT_FALSE(flags.carry);
    ASSERT_FALSE(flags.parity);
    ASSERT_FALSE(flags.half_carry);
    ASSERT_EQ(0x02, registers.accumulator);

    arithmetic.execute(0x82);
    ASSERT_FALSE(flags.sign);
    ASSERT_FALSE(flags.zero);
    ASSERT_FALSE(flags.carry);
    ASSERT_TRUE(flags.parity);
    ASSERT_FALSE(flags.half_carry);
    ASSERT_EQ(0x05, registers.accumulator);

    arithmetic.execute(0x83);
    ASSERT_FALSE(flags.sign);
    ASSERT_FALSE(flags.zero);
    ASSERT_FALSE(flags.carry);
    ASSERT_TRUE(flags.parity);
    ASSERT_FALSE(flags.half_carry);
    ASSERT_EQ(0x09, registers.accumulator);

    arithmetic.execute(0x84);
    ASSERT_FALSE(flags.sign);
    ASSERT_FALSE(flags.zero);
    ASSERT_FALSE(flags.carry);
    ASSERT_TRUE(flags.parity);
    ASSERT_FALSE(flags.half_carry);
    ASSERT_EQ(0x59, registers.accumulator);

    arithmetic.execute(0x85);
    ASSERT_FALSE(flags.sign);
    ASSERT_FALSE(flags.zero);
    ASSERT_FALSE(flags.carry);
    ASSERT_TRUE(flags.parity);
    ASSERT_FALSE(flags.half_carry);
    ASSERT_EQ(0x5f, registers.accumulator);

    arithmetic.execute(0x86);
    ASSERT_FALSE(flags.sign);
    ASSERT_FALSE(flags.zero);
    ASSERT_TRUE(flags.carry);
    ASSERT_FALSE(flags.parity);
    ASSERT_TRUE(flags.half_carry);
    ASSERT_EQ(0x5e, registers.accumulator);

    arithmetic.execute(0x87);
    ASSERT_TRUE(flags.sign);
    ASSERT_FALSE(flags.zero);
    ASSERT_FALSE(flags.carry);
    ASSERT_FALSE(flags.parity);
    ASSERT_TRUE(flags.half_carry);
    ASSERT_EQ(0xbc, registers.accumulator);
}

TEST_F(ArithmeticTestFixture, addWithCarry) {
    registers.b = 0x56;
    registers.c = 0x02;
    registers.d = 0x03;
    registers.e = 0x04;
    registers.h = 0x50;
    registers.l = 0x06;
    flags.carry = true;
    registers.accumulator = 0xaa;
    memory.write(0x5006, 0xff);

    arithmetic.execute(0x88);
    ASSERT_EQ(0x01, registers.accumulator);

    arithmetic.execute(0x89);
    ASSERT_EQ(0x04, registers.accumulator);

    arithmetic.execute(0x8a);
    ASSERT_EQ(0x07, registers.accumulator);

    arithmetic.execute(0x8b);
    ASSERT_EQ(0x0b, registers.accumulator);

    arithmetic.execute(0x8c);
    ASSERT_EQ(0x5b, registers.accumulator);

    arithmetic.execute(0x8d);
    ASSERT_EQ(0x61, registers.accumulator);

    arithmetic.execute(0x8e);
    ASSERT_EQ(0x60, registers.accumulator);

    arithmetic.execute(0x8f);
    ASSERT_EQ(0xc1, registers.accumulator);
}

TEST_F(ArithmeticTestFixture, addImmediate) {
    registers.accumulator = 0xaa;
    registers.program_counter = 0x5000;
    memory.write(0x5000, 0x56);
    memory.write(0x5001, 0xaa);

    arithmetic.execute(0xc6);
    ASSERT_EQ(0x00, registers.accumulator);
    ASSERT_EQ(0x5001, registers.program_counter);

    arithmetic.execute(0xce);
    ASSERT_EQ(0xab, registers.accumulator);
    ASSERT_EQ(0x5002, registers.program_counter);
}

TEST_F(ArithmeticTestFixture, addWrongOpcode) {
    registers.b = 0x01;
    registers.c = 0x02;
    registers.d = 0x03;
    registers.e = 0x04;
    registers.h = 0x50;
    registers.l = 0x06;
    registers.accumulator = 0x00;
    memory.write(0x5006, 0x07);

    flags.sign = true;
    flags.zero = true;
    flags.carry = true;
    flags.parity = true;
    flags.half_carry = true;

    arithmetic.execute(0x79);
    ASSERT_TRUE(flags.sign);
    ASSERT_TRUE(flags.zero);
    ASSERT_TRUE(flags.carry);
    ASSERT_TRUE(flags.parity);
    ASSERT_TRUE(flags.half_carry);
    ASSERT_EQ(0x00, registers.accumulator);
}
