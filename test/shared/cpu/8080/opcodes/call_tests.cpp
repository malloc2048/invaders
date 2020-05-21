#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/call.h"

TEST_F(OpCodeTestFixture, CALL_Disassemble) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0x00));
    ASSERT_TRUE(memory->write(0x0002, 0x00));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0003);
    ASSERT_EQ(out.str(), "cd\tCALL 0000");
}

TEST_F(OpCodeTestFixture, CALLConditional_Disassemble) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xc4));
    ASSERT_TRUE(memory->write(0x0001, 0x00));
    ASSERT_TRUE(memory->write(0x0002, 0x00));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0003);
    ASSERT_EQ(out.str(), "c4\tCNZ 0000");
}

TEST_F(OpCodeTestFixture, CALL_Execute) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xcd, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));
}

TEST_F(OpCodeTestFixture, CALLNotZero) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->zero = 0x00;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xc4, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->zero = 0x01;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xc4, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, CALLZero) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->zero = 0x01;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xcc, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->zero = 0x00;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xcc, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, CALLNoCarry) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->carry = 0x00;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xd4, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->carry = 0x01;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xd4, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, CALLCarry) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->carry = 0x01;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xdc, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->carry = 0x00;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xdc, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, CALLParityOdd) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->parity = 0x00;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xe4, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->parity = 0x01;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xe4, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, CALLParityEven) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->parity = 0x01;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xec, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->parity = 0x00;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xec, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, CALLPlus) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->sign = 0x00;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xf4, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->sign = 0x01;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xf4, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}

TEST_F(OpCodeTestFixture, CALLMinus) {
    CALL instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xcd));
    ASSERT_TRUE(memory->write(0x0001, 0xaa));
    ASSERT_TRUE(memory->write(0x0002, 0x18));

    flags->sign = 0x01;
    registers->sp.d16 = 0x2000;

    auto instructionSize = instruction.Execute(0xfc, out);
    ASSERT_EQ(0x00, instructionSize);
    ASSERT_EQ(0x1ffe, registers->sp.d16);
    ASSERT_EQ(0x18aa, registers->pc.d16);
    ASSERT_EQ(0x03, memory->read(registers->sp.d16));
    ASSERT_EQ(0x00, memory->read(registers->sp.d16 + 1));

    flags->sign = 0x00;
    registers->pc.d16 = 0x0000;
    registers->sp.d16 = 0x2000;

    instructionSize = instruction.Execute(0xfc, out);
    ASSERT_EQ(0x03, instructionSize);
    ASSERT_EQ(0x2000, registers->sp.d16);
    ASSERT_EQ(0x0000, registers->pc.d16);
}
