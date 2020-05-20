#include <thread>
#include <fstream>
#include <iostream>
#include "machine/video/videodriver.h"
#include "machine/cpu/8080/intel8080.h"

int main(int argc, char** argv) {
    Memory memory;
    Flags flags { .d8 = 0 };
    Registers regs { .a = 0, .pc = {.d16 = 0 }, .sp = {.d16 = 0 },
        .bc = {.d16 = 0 }, .de = {.d16 = 0 }, .hl = {.d16 = 0 },
        .intEnabled = 0
    };

    std::ofstream disassemblyFile;//("../../../roms/debug.out");
    Intel8080 cpu(&memory, &flags, &regs, disassemblyFile);

    auto romFile = fopen("../../../roms/invaders", "r");
    if(nullptr == romFile) {
        std::cout << "shit broke" << std::endl;
        return -1;
    }
    memory.loadRom(romFile);
    fclose(romFile);

    std::thread cpuThread(&Intel8080::Run, &cpu, true);

    VideoDriver vd(&memory);
    vd.setInterruptGenerateFunction(std::bind(&Intel8080::interrupt, &cpu, std::placeholders::_1 ));
    vd.draw();

    cpu.stop();
    cpuThread.join();

    return 0;
}
