#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/jump.h"

TEST_F(OpCodeTestFixture, Jump_Disassemble) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc3));
    ASSERT_TRUE(memory->write(0x0001, 0x00));
    ASSERT_TRUE(memory->write(0x0002, 0x00));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0003);
    ASSERT_EQ(out.str(), "c3\tJMP 0000");
}

TEST_F(OpCodeTestFixture, JumpConditional_Disassemble) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc2));
    ASSERT_TRUE(memory->write(0x0001, 0x00));
    ASSERT_TRUE(memory->write(0x0002, 0x00));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0003);
    ASSERT_EQ(out.str(), "c2\tJNZ 0000");
}

TEST_F(OpCodeTestFixture, Jump_Execute) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc3));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    auto instructionSize = instruction.Execute(0xc3, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpNotZero) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc2));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->zero = 0x00;

    auto instructionSize = instruction.Execute(0xc2, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->zero = 0x01;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xc2, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpZero) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xca));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->zero = 0x01;

    auto instructionSize = instruction.Execute(0xca, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->zero = 0x00;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xca, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpNoCarry) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xd2));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->carry = 0x00;

    auto instructionSize = instruction.Execute(0xd2, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->carry = 0x01;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xd2, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpCarry) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xda));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->carry = 0x01;

    auto instructionSize = instruction.Execute(0xda, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->carry = 0x00;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xda, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpParityOdd) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xe2));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->parity = 0x00;

    auto instructionSize = instruction.Execute(0xe2, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->parity = 0x01;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xe2, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpParityEven) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xea));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->parity = 0x01;

    auto instructionSize = instruction.Execute(0xea, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->parity = 0x00;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xea, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpPlus) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xf2));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->sign = 0x00;

    auto instructionSize = instruction.Execute(0xf2, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->sign = 0x01;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xf2, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, JumpMinus) {
    Jump instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xfa));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->sign = 0x01;

    auto instructionSize = instruction.Execute(0xfa, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x18aa, registers->pc.d16);

    flags->sign = 0x00;
    registers->pc.d16 = 0x0000;

    instructionSize = instruction.Execute(0xfa, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x0000, registers->pc.d16);
}
