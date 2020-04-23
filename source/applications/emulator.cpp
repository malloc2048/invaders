#include <ctime>
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
    char romFilename[256];

    if(argc == ARG_COUNT) {
        sprintf(romFilename, "%s/%s", argv[1], argv[2]);
    } else {
        sprintf(romFilename, "../../../config/invaders");
    }


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

    clock_t lastInterrupt = clock();
    while(cpu.registers.pc.d16 < romFileSize) {
        cpu.Emulate8080();

        if(clock() - lastInterrupt > 1.0/60.0) {
            if(cpu.registers.int_enable) {
                cpu.GenerateInterrupt(2);
                lastInterrupt = clock();
            }
        }
    }

    fclose(romFile);

    return 0;
}
