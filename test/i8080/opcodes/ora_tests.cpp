#include "OpCodeTestFixture.h"
#include "i8080/opcodes/ora.h"

TEST_F(OpCodeTestFixture, ORAB_WithCarrySet) {
    ORA instruction(flags, memory, registers);

    flags.carry = 0x01;
    flags.halfCarry = 0x01;
    registers.a = 0x55;
    registers.bc.bytes.high = 0xaa;

    instruction.Execute(0xb0);

    ASSERT_EQ(0xff, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ORAC_WithOutCarrySet) {
    ORA instruction(flags, memory, registers);

    registers.a = 0x55;
    registers.bc.bytes.low = 0xaa;

    instruction.Execute(0xb1);

    ASSERT_EQ(0xff, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ORAD) {
    ORA instruction(flags, memory, registers);

    registers.a = 0x80;
    registers.de.bytes.high = 0x01;

    instruction.Execute(0xb2);

    ASSERT_EQ(0x81, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ORAE) {
    ORA instruction(flags, memory, registers);

    registers.a = 0x0f;
    registers.de.bytes.low = 0xaa;

    instruction.Execute(0xb3);

    ASSERT_EQ(0xaf, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ORAH) {
    ORA instruction(flags, memory, registers);

    registers.a = 0x0f;
    flags.carry = 0x00;
    registers.hl.bytes.high = 0x03;

    instruction.Execute(0xb4);

    ASSERT_EQ(0x0f, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ORAL) {
    ORA instruction(flags, memory, registers);

    registers.a = 0x55;
    registers.hl.bytes.low = 0x84;

    instruction.Execute(0xb5);

    ASSERT_EQ(0xd5, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ORAM) {
    registers.a = 0xdc;
    registers.hl.d16 = Memory::ROM_SIZE;
    ORA instruction(flags, memory, registers);

    instruction.Execute(0xb6);
    ASSERT_EQ(0xdd, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ORAA) {
    ORA instruction(flags, memory, registers);

    registers.a = 0x01;
    flags.carry = 0x00;

    instruction.Execute(0xb7);

    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}
