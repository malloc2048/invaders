#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/adc.h"

TEST_F(OpCodeTestFixture, ADC_Disassemble) {
    ADC adc(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0x88));

    adc.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "88\tADC B");
}

TEST_F(OpCodeTestFixture, ADCB_WithCarrySet) {
    ADC adc(memory, flags, registers);

    registers->bc.bytes.high = 0x01;
    flags->carry = 0x01;

    auto instructionSize = adc.Execute(0x88, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x02, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ADCC_WithOutCarrySet) {
    ADC adc(memory, flags, registers);

    registers->bc.bytes.low = 0x01;

    auto instructionSize = adc.Execute(0x89, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ADCD_CarrySetByOperation) {
    ADC adc(memory, flags, registers);

    registers->a = 0x00;
    flags->carry = 0x00;
    registers->de.bytes.high = 0x01;

    auto instructionSize = adc.Execute(0x8a, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ADCE) {
    ADC adc(memory, flags, registers);

    registers->a = 0x00;
    flags->carry = 0x00;
    registers->de.bytes.low = 0x02;

    auto instructionSize = adc.Execute(0x8b, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x02, registers->a);
}

TEST_F(OpCodeTestFixture, ADCH) {
    ADC adc(memory, flags, registers);

    registers->a = 0x00;
    flags->carry = 0x00;
    registers->hl.bytes.high = 0x03;

    auto instructionSize = adc.Execute(0x8c, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x03, registers->a);
}

TEST_F(OpCodeTestFixture, ADCL) {
    ADC adc(memory, flags, registers);

    registers->a = 0x00;
    flags->carry = 0x00;
    registers->hl.bytes.low = 0x04;

    auto instructionSize = adc.Execute(0x8d, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x04, registers->a);
}

TEST_F(OpCodeTestFixture, ADCM) {
    ADC adc(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xaa));

    registers->a = 0x00;
    flags->carry = 0x00;
    registers->hl.d16 = 0x0000;

    auto instructionSize = adc.Execute(0x8e, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);
}

TEST_F(OpCodeTestFixture, ADCA) {
    ADC adc(memory, flags, registers);

    registers->a = 0x01;
    flags->carry = 0x00;

    auto instructionSize = adc.Execute(0x8f, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x02, registers->a);
}
