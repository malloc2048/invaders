#include "intel8080testfixture.h"

Intel8080TestFixture::Intel8080TestFixture(): ram(), flags(), regs(), cpu(&ram, &flags, &regs, outputStream) {

}

void Intel8080TestFixture::SetUp() {
    Test::SetUp();
}

void Intel8080TestFixture::loadTestMemory(std::vector<uint8_t>& values) {
    ram.loadRom();

    uint16_t address = 0x00;
    for(auto byte: values) {
        ram.write(address, byte);
        address++;
    }
    ram.lockRom();
}
