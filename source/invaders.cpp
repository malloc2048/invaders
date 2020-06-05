#include "invaders/cabinet.h"
#include "invaders/invaders.h"

int main(int argc, char** argv) {
    Cabinet cabinet;
    auto romFile = fopen(ROM_FILENAME, "r");

    if(nullptr != romFile) {
        cabinet.memory.loadRom(romFile);
        fclose(romFile);

        Invaders game(cabinet);
        game.run();
    } else {
        fprintf(stdout, "loading rom file failed");
    }
    return 0;
}
