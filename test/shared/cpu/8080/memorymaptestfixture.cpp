#include "common/config.h"
#include "memorymaptestfixture.h"

void MemoryMapTestFixture::SetUp() {
    TraceOff();
    Test::SetUp();
}

void MemoryMapTestFixture::SetMemory(int length, ...) const {

}
