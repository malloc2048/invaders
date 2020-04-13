#include "disassembler.h"
#include "opcodes/opcodes.h"
#include "common/utilities.h"

void Disassemble(FILE* romFile, FILE* output) {
    long fileLength = GetFileSize(romFile);
    unsigned char* buffer = ReadFile(romFile, fileLength);

    int jump = 1;
    for(long address = 0; address < fileLength; address += jump) {
        struct OpCode* opcode = GetOpCode(buffer[address]);

        fprintf(output, "%04lX\t", address);
        fprintf(output, "%02x\t", buffer[address]);
        fprintf(output, "%s", opcode->instruction);

        switch (opcode->size) {
            case 1:
                break;
            case 2:
                fprintf(output,"%02x", buffer[address + 1]);
                break;
            case 3: {
                fprintf(output, "%02x%02x", buffer[address + 2], buffer[address + 1]);
                break;
            }
            default: ;
                // NOP
        }
        fprintf(output, "\n");
        jump = opcode->size;
    }
}

