#include "../instruction_testfixture.h"

TEST_F(InstructionTestFixture, DCR_A) {
    SetMemory(4, 0x3d, 0x3d, 0x3d, 0x3d);

    cpu.registers.a = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.a == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}

TEST_F(InstructionTestFixture, DCR_B) {
    SetMemory(4, 0x05, 0x05, 0x05, 0x05);

    cpu.registers.bc.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.highByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.highByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.highByte == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}

TEST_F(InstructionTestFixture, DCR_C) {
    SetMemory(4, 0x0d, 0x0d, 0x0d, 0x0d);

    cpu.registers.bc.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.lowByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.lowByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.bc.d8.lowByte == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}

TEST_F(InstructionTestFixture, DCR_D) {
    SetMemory(4, 0x15, 0x15, 0x15, 0x15);

    cpu.registers.de.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.highByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.highByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.highByte == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}

TEST_F(InstructionTestFixture, DCR_E) {
    SetMemory(4, 0x1d, 0x1d, 0x1d, 0x1d);

    cpu.registers.de.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.lowByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.lowByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.de.d8.lowByte == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}

TEST_F(InstructionTestFixture, DCR_H) {
    SetMemory(4, 0x25, 0x25, 0x25, 0x25);

    cpu.registers.hl.d8.highByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.highByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.highByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.highByte == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}

TEST_F(InstructionTestFixture, DCR_L) {
    SetMemory(4, 0x2d, 0x2d, 0x2d, 0x2d);

    cpu.registers.hl.d8.lowByte = 0x01;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.lowByte == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.lowByte == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.hl.d8.lowByte == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}

TEST_F(InstructionTestFixture, DCR_M) {
    SetMemory(4, 0x35, 0x35, 0x35, 0x01);

    cpu.registers.hl.d16 = 0x03;
    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.memory[cpu.registers.hl.d16] == 0x00);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.memory[cpu.registers.hl.d16] == 0xff);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x02);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x01);

    cpu.Emulate8080();
    ASSERT_TRUE(cpu.registers.memory[cpu.registers.hl.d16] == 0xfe);
    ASSERT_TRUE(cpu.registers.pc.d16 == 0x03);
    ASSERT_TRUE(cpu.registers.psw.flags.z == 0x00);
    ASSERT_TRUE(cpu.registers.psw.flags.s == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.p == 0x01);
    ASSERT_TRUE(cpu.registers.psw.flags.ac == 0x00);
}
