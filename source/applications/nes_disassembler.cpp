#include <fstream>
#include <iostream>
#include "machine/cpu/6502/mos6502.h"
#include "machine/cpu/6502/opcodes/mnemonics.h"

int main(int argc, char** argv) {
    RAM memory;


    auto romFile = fopen("../../../roms/zelda.nes", "r");
    std::ofstream disassemblyFile("../../../roms/zelda.nes.dis");

    if(nullptr == romFile || !disassemblyFile.is_open()) {
        std::cout << "shit broke" << std::endl;
        return -1;
    }

    fseek(romFile, 0L, SEEK_END);
    auto romLength = ftell(romFile);
    fseek(romFile, 0L, SEEK_SET);

    std::cout << romLength << std::endl;

    for(auto i = 0; i < romLength; i++) {
        uint8_t byte = getc(romFile);

        if(Mnemonics::mnemonics.find(byte) != Mnemonics::mnemonics.end()) {
            std::cout << "0x" << std::hex << (unsigned)byte << std::endl;
        }

    }
    fclose(romFile);
    return 0;
}
