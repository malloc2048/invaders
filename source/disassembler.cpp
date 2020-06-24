#include <cstdio>
#include <iomanip>
#include "cabinet/constants.h"
#include "cabinet/memory.h"

int main() {
    std::ifstream rom_file(cabinet::ROM_FILENAME());
    std::ofstream disassembly_file(cabinet::DISASSEMBLY_FILENAME());

    cabinet::Memory memory;
    memory.load_rom(rom_file);

    for(uint32_t i = 0; i < 0x2000; ) {
        auto opcode = memory.read_byte(i);

        char disassembly[512];
        sprintf(disassembly, "%04x\t%02x\t%s", i, opcode, DISASSEMBLE_TABLE[opcode]);
        disassembly_file << disassembly;

        for(size_t j = OPCODES_LENGTH[opcode] - 1; j > 0; j--) {
            auto byte = memory.read_byte(i + j);
            disassembly_file << std::hex << std::setfill('0') << std::setw(2) << (uint32_t)byte;
        }
        disassembly_file << std::endl;
        i += OPCODES_LENGTH[opcode];
    }
    rom_file.close();
    disassembly_file.close();
    return 0;
}
