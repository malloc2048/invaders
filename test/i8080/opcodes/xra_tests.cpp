#include "OpCodeTestFixture.h"
#include "i8080/opcodes/xra.h"

TEST_F(OpCodeTestFixture, XRAB_WithCarrySet) {
    XRA instruction(flags, memory, registers);

    flags.carry = 0x01;
    flags.halfCarry = 0x01;
    registers.a = 0x55;
    registers.bc.bytes.high = 0xaa;

    instruction.Execute(0xa8);

    ASSERT_EQ(0xff, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, XRAC_WithOutCarrySet) {
    XRA instruction(flags, memory, registers);

    registers.a = 0x55;
    registers.bc.bytes.low = 0xff;

    instruction.Execute(0xa9);

    ASSERT_EQ(0xaa, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, XRAD) {
    XRA instruction(flags, memory, registers);

    registers.a = 0x80;
    registers.de.bytes.high = 0x01;

    instruction.Execute(0xaa);

    ASSERT_EQ(0x81, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, XRAE) {
    XRA instruction(flags, memory, registers);

    registers.a = 0xaa;
    registers.de.bytes.low = 0xaa;

    instruction.Execute(0xab);

    ASSERT_EQ(0x00, registers.a);
    ASSERT_EQ(0x01, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, XRAH) {
    XRA instruction(flags, memory, registers);

    registers.a = 0x0f;
    flags.carry = 0x00;
    registers.hl.bytes.high = 0x03;

    instruction.Execute(0xac);

    ASSERT_EQ(0x0c, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, XRAL) {
    XRA instruction(flags, memory, registers);

    registers.a = 0x55;
    registers.hl.bytes.low = 0x84;

    instruction.Execute(0xad);

    ASSERT_EQ(0xd1, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, XRAM) {
    registers.a = 0xdc;
    registers.hl.d16 = Memory::ROM_SIZE;
    XRA instruction(flags, memory, registers);

    instruction.Execute(0xae);
    ASSERT_EQ(0xdd, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, XRAA) {
    registers.a = 0x01;
    flags.carry = 0x00;
    XRA instruction(flags, memory, registers);

    instruction.Execute(0xaf);
    ASSERT_EQ(0x00, registers.a);
    ASSERT_EQ(0x01, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}
