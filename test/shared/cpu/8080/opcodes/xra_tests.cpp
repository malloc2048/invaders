#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/xra.h"

TEST_F(OpCodeTestFixture, XRA_Disassemble) {
    XRA instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xa8));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "a8\tXRA B");
}

TEST_F(OpCodeTestFixture, XRAB_WithCarrySet) {
    XRA instruction(memory, flags, registers);

    flags->carry = 0x01;
    flags->halfCarry = 0x01;
    registers->a = 0x55;
    registers->bc.bytes.high = 0xaa;

    auto instructionSize = instruction.Execute(0xa8, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xff, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, XRAC_WithOutCarrySet) {
    XRA instruction(memory, flags, registers);

    registers->a = 0x55;
    registers->bc.bytes.low = 0xff;

    auto instructionSize = instruction.Execute(0xa9, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, XRAD) {
    XRA instruction(memory, flags, registers);

    registers->a = 0x80;
    registers->de.bytes.high = 0x01;

    auto instructionSize = instruction.Execute(0xaa, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x81, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, XRAE) {
    XRA instruction(memory, flags, registers);

    registers->a = 0xaa;
    registers->de.bytes.low = 0xaa;

    auto instructionSize = instruction.Execute(0xab, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x00, registers->a);
    ASSERT_EQ(0x01, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, XRAH) {
    XRA instruction(memory, flags, registers);

    registers->a = 0x0f;
    flags->carry = 0x00;
    registers->hl.bytes.high = 0x03;

    auto instructionSize = instruction.Execute(0xac, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x0c, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, XRAL) {
    XRA instruction(memory, flags, registers);

    registers->a = 0x55;
    registers->hl.bytes.low = 0x84;

    auto instructionSize = instruction.Execute(0xad, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xd1, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, XRAM) {
    XRA instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xaa));

    registers->a = 0xdc;
    registers->hl.d16 = 0x0000;

    auto instructionSize = instruction.Execute(0xae, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x76, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, XRAA) {
    XRA instruction(memory, flags, registers);

    registers->a = 0x01;
    flags->carry = 0x00;

    auto instructionSize = instruction.Execute(0xaf, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}
