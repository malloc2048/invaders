#include "i8080/intel8080.h"
#include "invaders/cabinet.h"

int main(int argc, char** argv) {
    Cabinet cabinet;



    Flags flags;
    Memory memory;
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

    return 0;
}
