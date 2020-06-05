#include <cstdio>
#include "constants.h"
#include "memory/memory.h"

int main() {
    FILE* romfile = fopen(ROM_FILENAME, "r");
    FILE* disassemblyfile = fopen(DISASSEMBLY_FILENAME, "w");

    Memory memory;
    memory.loadRom(romfile);

    for(uint32_t i = 0; i < 0x2000; ) {
        auto opcode = memory.readByte(i);
        fprintf(disassemblyfile, "%04X\t%02x\t%s", i, opcode, DISASSEMBLE_TABLE[opcode]);

        for(size_t j = OPCODES_LENGTH[opcode] - 1; j > 0; j--) {
            auto byte = memory.readByte(i + j);
            fprintf(disassemblyfile, "%02x", byte);
        }
        fprintf(disassemblyfile, "\n");
        i += OPCODES_LENGTH[opcode];
    }

    fclose(romfile);
    fclose(disassemblyfile);

    return 0;
}
