#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/in.h"

TEST_F(OpCodeTestFixture, IN_Disassemble) {
    IN instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xdb));
    ASSERT_TRUE(memory->write(0x0001, 0x01));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0002);
    ASSERT_EQ(out.str(), "db\tIN 1");
}


