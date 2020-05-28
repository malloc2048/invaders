#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/cmp.h"

TEST_F(OpCodeTestFixture, CMP_Disassemble) {
    CMP instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xb8));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "b8\tCMP B");
}

TEST_F(OpCodeTestFixture, CMP_B) {
    CMP instruction(memory, flags, registers);

    registers->a = 0xaa;
    registers->bc.bytes.high = 0xaa;
    auto instructionSize = instruction.Execute(0xb8, out);

    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);

    ASSERT_EQ(flags->sign, 0x00);
    ASSERT_EQ(flags->zero, 0x01);
    ASSERT_EQ(flags->carry, 0x00);
    ASSERT_EQ(flags->parity, 0x01);
    ASSERT_EQ(flags->halfCarry, 0x00);
}

TEST_F(OpCodeTestFixture, CMP_C) {
    CMP instruction(memory, flags, registers);

    registers->a = 0xaa;
    registers->bc.bytes.low = 0x00;
    auto instructionSize = instruction.Execute(0xb9, out);

    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);

    ASSERT_EQ(flags->sign, 0x01);
    ASSERT_EQ(flags->zero, 0x00);
    ASSERT_EQ(flags->carry, 0x00);
    ASSERT_EQ(flags->parity, 0x01);
    ASSERT_EQ(flags->halfCarry, 0x01);
}

TEST_F(OpCodeTestFixture, CMP_D) {
    CMP instruction(memory, flags, registers);

    registers->a = 0xaa;
    registers->de.bytes.high = 0x55;
    auto instructionSize = instruction.Execute(0xba, out);

    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);

    ASSERT_EQ(flags->sign, 0x00);
    ASSERT_EQ(flags->zero, 0x00);
    ASSERT_EQ(flags->carry, 0x00);
    ASSERT_EQ(flags->parity, 0x01);
    ASSERT_EQ(flags->halfCarry, 0x00);
}

TEST_F(OpCodeTestFixture, CMP_E) {
    CMP instruction(memory, flags, registers);

    registers->a = 0xaa;
    registers->de.bytes.low = 0xff;
    auto instructionSize = instruction.Execute(0xbb, out);

    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);

    ASSERT_EQ(flags->sign, 0x01);
    ASSERT_EQ(flags->zero, 0x00);
    ASSERT_EQ(flags->carry, 0x00);
    ASSERT_EQ(flags->parity, 0x00);
    ASSERT_EQ(flags->halfCarry, 0x01);
}

TEST_F(OpCodeTestFixture, CMP_H) {
    CMP instruction(memory, flags, registers);

    registers->a = 0xaa;
    registers->hl.bytes.high = 0xff;
    auto instructionSize = instruction.Execute(0xbc, out);

    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);

    ASSERT_EQ(flags->sign, 0x01);
    ASSERT_EQ(flags->zero, 0x00);
    ASSERT_EQ(flags->carry, 0x00);
    ASSERT_EQ(flags->parity, 0x00);
    ASSERT_EQ(flags->halfCarry, 0x01);
}