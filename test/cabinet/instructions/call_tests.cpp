#include "OpCodeTestFixture.h"
#include "cabinet/instructions/call.h"

TEST_F(OpCodeTestFixture, CALL_Execute) {
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xcd);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));
}

TEST_F(OpCodeTestFixture, CALLNotZero) {
    flags.zero = 0x00;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xc4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.zero = 0x01;
    instruction.Execute(0xc4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, CALLZero) {
    flags.zero = 0x01;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xcc);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.zero = 0x00;
    instruction.Execute(0xcc);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, CALLNoCarry) {
    flags.carry = 0x00;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xd4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.carry = 0x01;
    instruction.Execute(0xd4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, CALLCarry) {
    flags.carry = 0x01;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xdc);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.carry = 0x00;
    instruction.Execute(0xdc);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, CALLParityOdd) {
    flags.parity = 0x00;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xe4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.parity = 0x01;
    instruction.Execute(0xe4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, CALLParityEven) {
    flags.parity = 0x01;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xec);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.parity = 0x00;
    instruction.Execute(0xec);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, CALLPlus) {
    flags.sign = 0x00;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xf4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.sign = 0x01;
    instruction.Execute(0xf4);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}

TEST_F(OpCodeTestFixture, CALLMinus) {
    flags.sign = 0x01;
    registers.sp.d16 = 0x2400;
    CALL instruction(flags, memory, registers);

    instruction.Execute(0xfc);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0201, registers.pc.d16);
    ASSERT_EQ(cabinet::Memory::ROM_SIZE + 2, memory.read_word(registers.sp.d16));

    flags.sign = 0x00;
    instruction.Execute(0xfc);
    ASSERT_EQ(0x23fe, registers.sp.d16);
    ASSERT_EQ(0x0203, registers.pc.d16);
}
