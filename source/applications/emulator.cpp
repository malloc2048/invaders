#include <cstdio>
#include <cstdlib>
#include "common/config.h"
#include "common/utilities.h"
#include "cpu/8080/intel8080.h"

static const int ARG_COUNT = 3;

void usage() {
    printf("Usage:\n");
    printf("\tcpu <path> <rom>\n");
    printf("\t<path>: file path to configuration files and rom files\n");
    printf("\t<rom>: rom file\n");
}

int main(int argc, char** argv) {
    if(argc != ARG_COUNT) {
        usage();
        printf("argc = %d", argc);
        exit(-1);
    }

    char romFilename[256];
    sprintf(romFilename, "%s/%s", argv[1], argv[2]);
    FILE* romFile = fopen(romFilename, "r");
    if(romFile == nullptr) {
        printf("unable to open rom file file %s", romFilename);
        exit(-1);
    }

    Intel8080 cpu;
    long romFileSize = ReadRomFile(romFile, cpu.registers.memory);
    if(config::IsHexDump()) {
        utilities::hexDump(cpu.registers.memory, romFileSize);
    }
    cpu.Run(romFileSize);
    fclose(romFile);

    return 0;
}
