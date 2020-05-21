#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/ori.h"

TEST_F(OpCodeTestFixture, ORI_Disassemble) {
    ORI instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xf6));
    ASSERT_TRUE(memory->write(0x0001, 0xff));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0002);
    ASSERT_EQ(out.str(), "f6\tORI ff");
}

TEST_F(OpCodeTestFixture, ORI) {
    ORI instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xf6));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));

    flags->carry = 1;
    flags->halfCarry = 1;
    registers->a = 0x55;

    auto instructionSize = instruction.Execute(0xe6, out);
    ASSERT_EQ(0x02, instructionSize);
    ASSERT_EQ(0xff, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}
