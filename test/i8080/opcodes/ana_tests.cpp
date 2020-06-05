#include "OpCodeTestFixture.h"
#include "i8080/opcodes/ana.h"

TEST_F(OpCodeTestFixture, ANAB_WithCarrySet) {
    ANA instruction(flags, memory, registers);

    flags.carry = 0x01;
    registers.a = 0x55;
    registers.bc.bytes.high = 0xaa;

    instruction.Execute(0xa0);
    ASSERT_EQ(0x00, registers.a);
    ASSERT_EQ(0x01, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x01, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ANAC_WithOutCarrySet) {
    ANA instruction(flags, memory, registers);

    registers.a = 0x55;
    registers.bc.bytes.low = 0xff;

    instruction.Execute(0xa1);
    ASSERT_EQ(0x55, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x01, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ANAD_CarrySetByOperation) {
    ANA instruction(flags, memory, registers);

    registers.a = 0xff;
    flags.carry = 0x00;
    registers.de.bytes.high = 0x01;

    instruction.Execute(0xa2);
    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x01, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ANAE) {
    ANA instruction(flags, memory, registers);

    registers.a = 0xff;
    flags.carry = 0x00;
    registers.de.bytes.low = 0xaa;

    instruction.Execute(0xa3);

    ASSERT_EQ(0xaa, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x01, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ANAH) {
    ANA instruction(flags, memory, registers);

    registers.a = 0x0f;
    flags.carry = 0x00;
    registers.hl.bytes.high = 0x03;

    instruction.Execute(0xa4);

    ASSERT_EQ(0x03, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x01, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ANAL) {
    ANA instruction(flags, memory, registers);

    registers.a = 0x55;
    flags.carry = 0x00;
    registers.hl.bytes.low = 0x84;

    instruction.Execute(0xa5);

    ASSERT_EQ(0x04, registers.a);
}

TEST_F(OpCodeTestFixture, ANAM) {
    registers.a = 0xdc;
    registers.hl.d16 = Memory::ROM_SIZE;
    ANA instruction(flags, memory, registers);

    instruction.Execute(0xa6);
    ASSERT_EQ(0x00, registers.a);
}

TEST_F(OpCodeTestFixture, ANAA) {
    registers.a = 0x01;
    ANA instruction(flags, memory, registers);

    instruction.Execute(0xa7);
    ASSERT_EQ(0x01, registers.a);
}
