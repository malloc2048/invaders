#include "OpCodeTestFixture.h"
#include "cabinet/instructions/instruction.h"

//    void updateCarry(uint8_t original, uint8_t updated) ;

class OpCodeTestImpl : public Instruction {
public:
    OpCodeTestImpl(cabinet::Flags& flags, cabinet::Memory& memory, Registers& registers): Instruction(flags, memory, registers){}

    void Execute(uint8_t opcode) override {};
};

TEST_F(OpCodeTestFixture, OpCode_UpdateFlags_Zero) {
    OpCodeTestImpl opcode(flags, memory, registers);
    opcode.updateFlags(0x00);

    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x01, flags.zero);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x01, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, OpCode_UpdateFlags_Sign) {
    OpCodeTestImpl opcode(flags, memory, registers);
    opcode.updateFlags(0x80);

    ASSERT_EQ(0x01, flags.sign);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x00, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x00, flags.halfCarry);
}

TEST_F(OpCodeTestFixture, OpCode_HalfCarry) {
    OpCodeTestImpl opcode(flags, memory, registers);

    // This test when a register would roll over
    opcode.updateCarry(0x01, 0xff);

    ASSERT_EQ(0x00, flags.sign);
    ASSERT_EQ(0x00, flags.zero);
    ASSERT_EQ(0x01, flags.carry);
    ASSERT_EQ(0x00, flags.parity);
    ASSERT_EQ(0x01, flags.halfCarry);
}
