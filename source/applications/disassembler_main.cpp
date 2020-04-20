#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include "opcodes/opcodes.h"
#include "disassembler/disassembler.h"

void usage() {
    printf("Usage:\n");
    printf("\tdisassembler <path> <cpu_config> <rom>\n");
    printf("\t<path>: file path to configuration files and rom files\n");
    printf("\t<cpu_config> filename of CPU configuration\n");
    printf("\t<rom> ROM filename to disassemble\n");
}

int main(int argc, char** argv) {
    if(argc != 4) {
        usage();
        exit(-1);
    }

    char cpuCfgFile[256];
    sprintf(cpuCfgFile, "%s/%s", argv[1], argv[2]);
    FILE* cpuCfg = fopen(cpuCfgFile, "r");
    if(cpuCfg == nullptr) {
        printf("unable to open CPU configuration file %s", cpuCfgFile);
        exit(errno);
    }
    Load(cpuCfg);
    fclose(cpuCfg);

    char romFilename[256];
    sprintf(romFilename, "%s/%s", argv[1], argv[3]);
    FILE *romFile = fopen(romFilename, "r");
    if(romFile == nullptr) {
        printf("unable to open ROM file %s", romFilename);
        exit(errno);
    }

    char outputFilename[260];
    sprintf(outputFilename, "%s.dis", romFilename);
    FILE *disFile = fopen(outputFilename, "w");
    if(disFile == nullptr) {
        printf("unable to open output file %s", outputFilename);
        exit(errno);
    }

    Disassemble(romFile, disFile);
    fclose(romFile);
    fclose(disFile);

    return 0;
}
