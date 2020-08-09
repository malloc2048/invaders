#include <fstream>
#include "invaders.h"

int main(int argc, char** argv) {
    common::Config cfg;
    cfg.loadConfig(common::ConfigFileName());

    std::ifstream rom_file(cfg.getString("ROM_FILENAME"));
    if(rom_file.is_open()) {
        Invaders game(cfg);
        game.load_rom(rom_file);
        rom_file.close();

        game.run();
    } else {
        fprintf(stdout, "loading rom file failed");
    }
    return 0;
}
