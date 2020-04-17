#include "arithmetictestfixture.h"

void ArithmeticTestFixture::SetUp() {
    TraceOff();
}

void ArithmeticTestFixture::SetMemory(uint8_t value, size_t length, size_t start) const {
    for(size_t index = 0; index < length; index++) {
        cpu.state.memory[index] = value;
    }
}
