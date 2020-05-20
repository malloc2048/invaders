#include "OpCodeTestFixture.h"
#include "machine/cpu/8080/opcode.h"

//    void updateCarry(uint8_t original, uint8_t updated) ;

class OpCodeTestImpl : public OpCode {
public:
    OpCodeTestImpl(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode, std::ostream& debug) override { return 1; };
    void Disassemble(std::ostream& out) override {}
};

TEST_F(OpCodeTestFixture, OpCode_UpdateFlags_Zero) {
    OpCodeTestImpl opcode(memory, flags, registers);
    opcode.updateFlags(0x00);

    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x01, flags->zero);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x01, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, OpCode_UpdateFlags_Sign) {
    OpCodeTestImpl opcode(memory, flags, registers);
    opcode.updateFlags(0x80);

    ASSERT_EQ(0x01, flags->sign);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x00, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x00, flags->halfCarry);
}

TEST_F(OpCodeTestFixture, OpCode_HalfCarry) {
    OpCodeTestImpl opcode(memory, flags, registers);

    // This test when a register would roll over
    opcode.updateCarry(0x01, 0xff);

    ASSERT_EQ(0x00, flags->sign);
    ASSERT_EQ(0x00, flags->zero);
    ASSERT_EQ(0x01, flags->carry);
    ASSERT_EQ(0x00, flags->parity);
    ASSERT_EQ(0x01, flags->halfCarry);
}
