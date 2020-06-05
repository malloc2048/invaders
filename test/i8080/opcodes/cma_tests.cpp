#include "OpCodeTestFixture.h"
#include "i8080/opcodes/cma.h"

TEST_F(OpCodeTestFixture, CMA_Execute_CarryZero) {
    CMA instruction(flags, memory, registers);

    registers.a = 0xaa;
    instruction.Execute(0x2f);

    ASSERT_EQ(registers.a, 0x55);
}
