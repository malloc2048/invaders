#ifndef INVADERS_INVADERS_H
#define INVADERS_INVADERS_H

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <hardware/cabinet.h>
#include "hardware/i8080/cpu.h"

class Invaders {
public:
    explicit Invaders(common::Config& cfg);
    ~Invaders();

    void run();
    void load_rom(std::ifstream &rom_file);

protected:
    void mainLoop();
    void gpuUpdate();
    bool windowInit();
    void pollEvents();
    void gameUpdate();
    bool hardwareInit();
    void updateScreen();

    void handleIn();
    void handleOut();
    void handleKeyUp(SDL_Scancode keyCode);
    void handleKeyDown(SDL_Scancode keyCode);

private:
    uint32_t timer = 0;
    common::Config& cfg;
    bool shouldQuit = false;
    bool initialized = false;
    hardware::Cabinet cabinet;

    SDL_Window* window = nullptr;
    SDL_Texture* texture = nullptr;
    SDL_Renderer* renderer = nullptr;
};
#endif
