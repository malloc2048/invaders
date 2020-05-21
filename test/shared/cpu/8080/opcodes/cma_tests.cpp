#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/cma.h"

TEST_F(OpCodeTestFixture, CMA_Disassemble) {
    CMA instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0x2f));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "2f\tCMA");
}

TEST_F(OpCodeTestFixture, CMA_Execute_CarryZero) {
    CMA instruction(memory, flags, registers);

    registers->a = 0xaa;
    auto instructionSize = instruction.Execute(0x2f, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(registers->a, 0x55);
}
