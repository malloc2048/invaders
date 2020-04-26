#include <iostream>
#include "machine/cpu/8080/intel8080.h"

int main(int argc, char** argv) {
    RAM memory;
    Flags flags { .d8 = 0 };
    Registers regs { .a = 0, .pc = {.d16 = 0 }, .sp = {.d16 = 0 },
        .bc = {.d16 = 0 }, .de = {.d16 = 0 }, .hl = {.d16 = 0 },
        .intEnabled = 0
    };

    Intel8080 cpu(&memory, &flags, &regs, std::cout);
    auto romFile = fopen("../../../roms/invaders", "r");
    if(nullptr == romFile) {
        std::cout << "shit broke" << std::endl;
        return -1;
    }
    memory.loadRom(romFile);
    fclose(romFile);

    while(regs.pc.d16 < RAM::ROM_MAX_ADDR) {
        cpu.tick(true);
    }
    return 0;
}
