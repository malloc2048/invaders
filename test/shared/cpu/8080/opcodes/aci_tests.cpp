#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/aci.h"

TEST_F(OpCodeTestFixture, ACI_Disassemble) {
    ACI instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xCE));
    ASSERT_TRUE(memory->write(0x0001, 0x01));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0002);
    ASSERT_EQ(out.str(), "ce\tACI 1");
}

TEST_F(OpCodeTestFixture, ACI_Execute_CarryZero) {
    ACI instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xCE));
    ASSERT_TRUE(memory->write(0x0001, 0x01));

    auto instructionSize = instruction.Execute(0xCE, out);
    ASSERT_EQ(0x02, instructionSize);
    ASSERT_EQ(registers->a, 0x01);
}

TEST_F(OpCodeTestFixture, ACI_Execute_CarrySet) {
    ACI instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xCE));
    ASSERT_TRUE(memory->write(0x0001, 0x01));

    flags->carry = 1;

    auto instructionSize = instruction.Execute(0xCE, out);
    ASSERT_EQ(0x02, instructionSize);
    ASSERT_EQ(registers->a, 0x02);
}

TEST_F(OpCodeTestFixture, ACI_Execute_CarryFlagSet) {
    ACI instruction(memory, flags, registers);

    registers->a = 0x01;

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xCE));
    ASSERT_TRUE(memory->write(0x0001, 0xff));

    auto instructionSize = instruction.Execute(0xCE, out);
    ASSERT_EQ(0x02, instructionSize);
    ASSERT_EQ(registers->a, 0x00);
}

TEST_F(OpCodeTestFixture, ACI_Execute_SignFlagSet) {
    ACI instruction(memory, flags, registers);

    registers->a = 0x70;

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xCE));
    ASSERT_TRUE(memory->write(0x0001, 0x80));

    auto instructionSize = instruction.Execute(0xCE, out);
    ASSERT_EQ(0x02, instructionSize);
    ASSERT_EQ(registers->a, 0xf0);
}
