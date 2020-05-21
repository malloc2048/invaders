#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/ora.h"

TEST_F(OpCodeTestFixture, ORA_Disassemble) {
    ORA instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xb0));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "b0\tORA B");
}

TEST_F(OpCodeTestFixture, ORAB_WithCarrySet) {
    ORA instruction(memory, flags, registers);

    flags->carry = 0x01;
    flags->halfCarry = 0x01;
    registers->a = 0x55;
    registers->bc.bytes.high = 0xaa;

    auto instructionSize = instruction.Execute(0xb0, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xff, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ORAC_WithOutCarrySet) {
    ORA instruction(memory, flags, registers);

    registers->a = 0x55;
    registers->bc.bytes.low = 0xaa;

    auto instructionSize = instruction.Execute(0xb1, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xff, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ORAD) {
    ORA instruction(memory, flags, registers);

    registers->a = 0x80;
    registers->de.bytes.high = 0x01;

    auto instructionSize = instruction.Execute(0xb2, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x81, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ORAE) {
    ORA instruction(memory, flags, registers);

    registers->a = 0x0f;
    registers->de.bytes.low = 0xaa;

    auto instructionSize = instruction.Execute(0xb3, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaf, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ORAH) {
    ORA instruction(memory, flags, registers);

    registers->a = 0x0f;
    flags->carry = 0x00;
    registers->hl.bytes.high = 0x03;

    auto instructionSize = instruction.Execute(0xb4, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x0f, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ORAL) {
    ORA instruction(memory, flags, registers);

    registers->a = 0x55;
    registers->hl.bytes.low = 0x84;

    auto instructionSize = instruction.Execute(0xb5, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xd5, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ORAM) {
    ORA instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xaa));

    registers->a = 0xdc;
    registers->hl.d16 = 0x0000;

    auto instructionSize = instruction.Execute(0xb6, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xfe, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ORAA) {
    ORA instruction(memory, flags, registers);

    registers->a = 0x01;
    flags->carry = 0x00;

    auto instructionSize = instruction.Execute(0xb7, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}
