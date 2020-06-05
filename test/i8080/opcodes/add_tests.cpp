#include "OpCodeTestFixture.h"
#include "i8080/opcodes/add.h"

TEST_F(OpCodeTestFixture, ADDB_WithCarrySet) {
    ADD instruction(flags, memory, registers);

    registers.bc.bytes.high = 0x01;

    instruction.Execute(0x80);

    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ADDC_WithOutCarrySet) {
    ADD instruction(flags, memory, registers);

    registers.bc.bytes.low = 0x01;

    instruction.Execute(0x81);

    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ADDD_CarrySetByOperation) {
    ADD instruction(flags, memory, registers);

    registers.a = 0x00;
    registers.de.bytes.high = 0x01;

    instruction.Execute(0x82);

    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ADDE) {
    ADD instruction(flags, memory, registers);

    registers.a = 0x00;
    registers.de.bytes.low = 0x02;

    instruction.Execute(0x83);

    ASSERT_EQ(0x02, registers.a);
}

TEST_F(OpCodeTestFixture, ADDH) {
    ADD instruction(flags, memory, registers);

    registers.a = 0x00;
    registers.hl.bytes.high = 0x03;

    instruction.Execute(0x84);

    ASSERT_EQ(0x03, registers.a);
}

TEST_F(OpCodeTestFixture, ADDL) {
    ADD instruction(flags, memory, registers);

    registers.a = 0x00;
    registers.hl.bytes.low = 0x04;

    instruction.Execute(0x85);

    ASSERT_EQ(0x04, registers.a);
}

TEST_F(OpCodeTestFixture, ADDM) {
    ADD instruction(flags, memory, registers);
    registers.a = 0xa9;
    registers.hl.d16 = Memory::ROM_SIZE;

    instruction.Execute(0x86);
    ASSERT_EQ(0xaa, registers.a);
}

TEST_F(OpCodeTestFixture, ADDA) {
    ADD instruction(flags, memory, registers);

    registers.a = 0x01;

    instruction.Execute(0x87);

    ASSERT_EQ(0x02, registers.a);
}
