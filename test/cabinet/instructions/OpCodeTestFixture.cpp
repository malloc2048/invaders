#include "OpCodeTestFixture.h"

void OpCodeTestFixture::SetUp() {
    Test::SetUp();
    registers.pc.d16 = cabinet::Memory::ROM_SIZE;
    memory.write(cabinet::Memory::ROM_SIZE, 0x01);
    memory.write(cabinet::Memory::ROM_SIZE + 1, 0x02);
}
