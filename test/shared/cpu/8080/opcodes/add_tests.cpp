#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcodes/add.h"

TEST_F(OpCodeTestFixture, ADD_Disassemble) {
    ADD instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0x80));

    instruction.Disassemble(out);
    ASSERT_EQ(registers->pc.d16, 0x0001);
    ASSERT_EQ(out.str(), "80\tADD B");
}

TEST_F(OpCodeTestFixture, ADDB_WithCarrySet) {
    ADD instruction(memory, flags, registers);

    registers->bc.bytes.high = 0x01;

    auto instructionSize = instruction.Execute(0x80, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ADDC_WithOutCarrySet) {
    ADD instruction(memory, flags, registers);

    registers->bc.bytes.low = 0x01;

    auto instructionSize = instruction.Execute(0x81, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ADDD_CarrySetByOperation) {
    ADD instruction(memory, flags, registers);

    registers->a = 0x00;
    registers->de.bytes.high = 0x01;

    auto instructionSize = instruction.Execute(0x82, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x01, registers->a);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, ADDE) {
    ADD instruction(memory, flags, registers);

    registers->a = 0x00;
    registers->de.bytes.low = 0x02;

    auto instructionSize = instruction.Execute(0x83, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x02, registers->a);
}

TEST_F(OpCodeTestFixture, ADDH) {
    ADD instruction(memory, flags, registers);

    registers->a = 0x00;
    registers->hl.bytes.high = 0x03;

    auto instructionSize = instruction.Execute(0x84, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x03, registers->a);
}

TEST_F(OpCodeTestFixture, ADDL) {
    ADD instruction(memory, flags, registers);

    registers->a = 0x00;
    registers->hl.bytes.low = 0x04;

    auto instructionSize = instruction.Execute(0x85, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x04, registers->a);
}

TEST_F(OpCodeTestFixture, ADDM) {
    ADD instruction(memory, flags, registers);

    memory->loadRom();
    ASSERT_TRUE(memory->write(0x0000, 0xaa));

    registers->a = 0x00;
    registers->hl.d16 = 0x0000;

    auto instructionSize = instruction.Execute(0x86, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0xaa, registers->a);
}

TEST_F(OpCodeTestFixture, ADDA) {
    ADD instruction(memory, flags, registers);

    registers->a = 0x01;

    auto instructionSize = instruction.Execute(0x87, out);
    ASSERT_EQ(0x01, instructionSize);
    ASSERT_EQ(0x02, registers->a);
}
