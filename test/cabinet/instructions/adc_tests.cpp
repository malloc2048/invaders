#include "OpCodeTestFixture.h"
#include "cabinet/instructions/adc.h"

TEST_F(OpCodeTestFixture, ADCB_WithCarrySet) {
    ADC instruction(flags, memory, registers);
    registers.bc.bytes.high = 0x01;
    flags.carry = 0x01;

    instruction.Execute(0x88);
    ASSERT_EQ(0x02, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ADCC_WithOutCarrySet) {
    registers.bc.bytes.low = 0x01;
    ADC instruction(flags, memory, registers);

    instruction.Execute(0x89);
    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ADCD_CarrySetByOperation) {
    registers.a = 0x00;
    flags.carry = 0x00;
    registers.de.bytes.high = 0x01;
    ADC instruction(flags, memory, registers);

    instruction.Execute(0x8a);
    ASSERT_EQ(0x01, registers.a);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, ADCE) {
    registers.a = 0x00;
    flags.carry = 0x00;
    registers.de.bytes.low = 0x02;
    ADC instruction(flags, memory, registers);

    instruction.Execute(0x8b);
    ASSERT_EQ(0x02, registers.a);
}

TEST_F(OpCodeTestFixture, ADCH) {
    registers.a = 0x00;
    flags.carry = 0x00;
    registers.hl.bytes.high = 0x03;
    ADC instruction(flags, memory, registers);

    instruction.Execute(0x8c);
    ASSERT_EQ(0x03, registers.a);
}

TEST_F(OpCodeTestFixture, ADCL) {
    registers.a = 0x00;
    flags.carry = 0x00;
    registers.hl.bytes.low = 0x04;
    ADC instruction(flags, memory, registers);

    instruction.Execute(0x8d);
    ASSERT_EQ(0x04, registers.a);
}

TEST_F(OpCodeTestFixture, ADCM) {
    ADC instruction(flags, memory, registers);
    registers.a = 0x00;
    flags.carry = 0x00;
    registers.hl.d16 = cabinet::Memory::ROM_SIZE;

    instruction.Execute(0x8e);
    ASSERT_EQ(0x01, registers.a);
}

TEST_F(OpCodeTestFixture, ADCA) {
    ADC instruction(flags, memory, registers);

    registers.a = 0x01;
    flags.carry = 0x00;

    instruction.Execute(0x8f);

    ASSERT_EQ(0x02, registers.a);
}
