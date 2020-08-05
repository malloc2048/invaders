#include <fstream>
#include "invaders.h"

int main(int argc, char** argv) {
    std::ifstream rom_file(hardware::ROM_FILENAME());

    if(rom_file.is_open()) {
        Invaders game;
        game.load_rom(rom_file);
        rom_file.close();

        game.run();
    } else {
        fprintf(stdout, "loading rom file failed");
    }
    return 0;
}
