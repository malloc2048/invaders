#include "OpCodeTestFixture.h"
#include "cabinet/instructions/cpi.h"

TEST_F(OpCodeTestFixture, CPI) {
    CPI instruction(flags, memory, registers);

    registers.a = 0xaa;
    registers.pc.d16 = 0x2000;
    memory.write(0x2000, 0xff);
    instruction.Execute(0xfe);

    ASSERT_EQ(flags.sign, 0x01);
    ASSERT_EQ(flags.zero, 0x00);
    ASSERT_EQ(flags.carry, 0x01);
    ASSERT_EQ(flags.parity, 0x00);
    ASSERT_EQ(flags.halfCarry, 0x01);
}
