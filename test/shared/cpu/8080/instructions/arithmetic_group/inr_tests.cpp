#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, INR_A) {
    SetMemory(4, 0x3c, 0x3c, 0x3c, 0x3c);

    cpu.registers.a = 0xfe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}

TEST_F(InstructionTestFixture, INR_B) {
    SetMemory(4, 0x04, 0x04, 0x04, 0x04);

    cpu.registers.bc.d8.highByte = 0xfe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.highByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.highByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}

TEST_F(InstructionTestFixture, INR_C) {
    SetMemory(4, 0x0c, 0x0c, 0x0c, 0x0c);

    cpu.registers.bc.d8.lowByte = 0xfe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.lowByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.lowByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}

TEST_F(InstructionTestFixture, INR_D) {
    SetMemory(4, 0x14, 0x14, 0x14, 0x14);

    cpu.registers.de.d8.highByte = 0xfe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.highByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.highByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}

TEST_F(InstructionTestFixture, INR_E) {
    SetMemory(4, 0x1c, 0x1c, 0x1c, 0x1c);

    cpu.registers.de.d8.lowByte = 0xfe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.lowByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.lowByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}

TEST_F(InstructionTestFixture, INR_H) {
    SetMemory(4, 0x24, 0x24, 0x24, 0x24);

    cpu.registers.hl.d8.highByte = 0xfe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.highByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.highByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}

TEST_F(InstructionTestFixture, INR_L) {
    SetMemory(4, 0x2c, 0x2c, 0x2c, 0x2c);

    cpu.registers.hl.d8.lowByte = 0xfe;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.lowByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.lowByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}

TEST_F(InstructionTestFixture, INR_M) {
    SetMemory(3, 0x34, 0x34, 0xfe);

    cpu.registers.hl.d16 = 0x0002;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.memory[cpu.registers.hl.d16] == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.memory[cpu.registers.hl.d16] == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);
}
