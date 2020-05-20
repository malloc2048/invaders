#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/adi.h"

TEST_F(OpCodeTestFixture, ADI_Disassemble) {
    ADI instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc6));
    ASSERT_TRUE(memory->write(0x0001, 0x00));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0002);
    ASSERT_EQ(out.str(), "c6\tADI 00");
}

TEST_F(OpCodeTestFixture, ADI_NoCarry) {
    ADI instruction(memory, flags, registers);

    registers->a = 0x01;
    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc6));
    ASSERT_TRUE(memory->write(0x0001, 0x01));

    auto instructionSize = instruction.Execute(0xc6, out);
    ASSERT_EQ(0x02, instructionSize);
    ASSERT_EQ(0x02, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ADIC_Carry) {
    ADI instruction(memory, flags, registers);

    registers->a = 0xff;
    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc6));
    ASSERT_TRUE(memory->write(0x0001, 0x01));

    auto instructionSize = instruction.Execute(0xc6, out);
    ASSERT_EQ(0x02, instructionSize);
    ASSERT_EQ(0x00, registers->a);
    ASSERT_EQ(0x01, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x01, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}
