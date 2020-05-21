#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/ana.h"

TEST_F(OpCodeTestFixture, ANA_Disassemble) {
    ANA instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xa0));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "a0\tANA B");
}

TEST_F(OpCodeTestFixture, ANAB_WithCarrySet) {
    ANA instruction(memory, flags, registers);

    flags->carry = 0x01;
    registers->a = 0x55;
    registers->bc.bytes.high = 0xaa;

    auto instructionSize = instruction.Execute(0xa0, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x00, registers->a);
    ASSERT_EQ(0x01, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ANAC_WithOutCarrySet) {
    ANA instruction(memory, flags, registers);

    registers->a = 0x55;
    registers->bc.bytes.low = 0xff;

    auto instructionSize = instruction.Execute(0xa1, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x55, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ANAD_CarrySetByOperation) {
    ANA instruction(memory, flags, registers);

    registers->a = 0xff;
    flags->carry = 0x00;
    registers->de.bytes.high = 0x01;

    auto instructionSize = instruction.Execute(0xa2, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x01, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ANAE) {
    ANA instruction(memory, flags, registers);

    registers->a = 0xff;
    flags->carry = 0x00;
    registers->de.bytes.low = 0xaa;

    auto instructionSize = instruction.Execute(0xa3, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x01, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ANAH) {
    ANA instruction(memory, flags, registers);

    registers->a = 0x0f;
    flags->carry = 0x00;
    registers->hl.bytes.high = 0x03;

    auto instructionSize = instruction.Execute(0xa4, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x03, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x01, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ANAL) {
    ANA instruction(memory, flags, registers);

    registers->a = 0x55;
    flags->carry = 0x00;
    registers->hl.bytes.low = 0x84;

    auto instructionSize = instruction.Execute(0xa5, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x04, registers->a);
}

TEST_F(OpCodeTestFixture, ANAM) {
    ANA instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xaa));

    registers->a = 0xdc;
    flags->carry = 0x00;
    registers->hl.d16 = 0x0000;

    auto instructionSize = instruction.Execute(0xa6, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x88, registers->a);
}

TEST_F(OpCodeTestFixture, ANAA) {
    ANA instruction(memory, flags, registers);

    registers->a = 0x01;
    flags->carry = 0x00;

    auto instructionSize = instruction.Execute(0xa7, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
}
