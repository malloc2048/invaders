#include <cstdio>
#include <cstdlib>
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
        exit(errno);
    }
    State8080 state = { .a = 0, .b = 0, .c = 0, .d = 0, .e = 0, .h = 0, .l = 0, .sp = 0, .pc = 0,
        .memory = (uint8_t*)malloc(sizeof(uint8_t) * 65536),
        .cc = ConditionCodes{ .z = 0, .s = 0, .p = 0, .cy = 0, .ac = 0, .pad = 0}, .int_enable = 0
    };
    long romFileSize = ReadRomFile(romFile, state.memory);
    fclose(romFile);
    Run(&state, romFileSize);

    return 0;
}
