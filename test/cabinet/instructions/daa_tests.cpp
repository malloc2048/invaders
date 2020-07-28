#include "OpCodeTestFixture.h"
#include "cabinet/instructions/daa.h"

TEST_F(OpCodeTestFixture, DAA) {
    DAA instruction(flags, memory, registers);
}
