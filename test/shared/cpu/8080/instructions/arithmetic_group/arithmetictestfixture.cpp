#include "arithmetictestfixture.h"

ArithmeticTestFixture::ArithmeticTestFixture() : state() {
    state = {
        .a = 0, .b = 0, .c = 0, .d = 0, .e = 0, .h = 0, .l = 0, .sp = 0, .pc = 0,
        .memory = (uint8_t*)malloc(sizeof(uint8_t) * 8),
        .cc = ConditionCodes{ .z = 0, .s = 0, .p = 0, .cy = 0, .ac = 0, .pad = 0}, .int_enable = 0
    };
}

void ArithmeticTestFixture::SetUp() {
    TraceOff();
}

void ArithmeticTestFixture::SetMemory(uint8_t value, size_t length, size_t start) const {
    for(size_t index = 0; index < length; index++) {
        state.memory[index] = value;
    }
}
