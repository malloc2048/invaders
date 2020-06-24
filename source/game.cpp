#include <fstream>
#include "cabinet/cabinet.h"
#include "invaders/invaders.h"

int main(int argc, char** argv) {
    cabinet::Cabinet cabinet;
    std::ifstream rom_file(cabinet::ROM_FILENAME());

    if(rom_file.is_open()) {
        cabinet.memory.load_rom(rom_file);
        rom_file.close();

        Invaders game(cabinet);
        game.run();
    } else {
        fprintf(stdout, "loading rom file failed");
    }
    return 0;
}
