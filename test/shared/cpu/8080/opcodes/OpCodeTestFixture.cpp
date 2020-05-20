#include "OpCodeTestFixture.h"

OpCodeTestFixture::OpCodeTestFixture() : flags(new Flags), memory(new Memory), registers(new Registers) {

}

OpCodeTestFixture::~OpCodeTestFixture() {
    delete flags;
    delete memory;
    delete registers;
}

void OpCodeTestFixture::SetUp() {
    Test::SetUp();
}
