#include "../intel8080testfixture.h"

TEST_F(Intel8080TestFixture, STAX_Test) {
    std::vector<uint8_t> testMemory = {
        0x02, 0x12
    };
    loadTestMemory(testMemory);

    regs.a = 0xaa;
    regs.bc.d16 = 0x2000;
    regs.de.d16 = 0x2001;

    ASSERT_EQ(ram.read(regs.bc.d16), 0x00);
    cpu.tick();
    ASSERT_EQ(ram.read(regs.bc.d16), 0xaa);
    ASSERT_EQ(regs.pc.d16, 0x0001);

    ASSERT_EQ(ram.read(regs.de.d16), 0x00);
    cpu.tick();
    ASSERT_EQ(ram.read(regs.de.d16), 0xaa);
    ASSERT_EQ(regs.pc.d16, 0x0002);
}
