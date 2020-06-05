#ifndef INVADERS_INVADERS_H
#define INVADERS_INVADERS_H

#include "cabinet.h"
#include <SDL2/SDL.h>

class Invaders {
public:
    Invaders(Cabinet& cabinet);
    ~Invaders();

    void run();

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

private:
    Cabinet& cabinet;
    uint32_t timer = 0;
    bool shouldQuit = false;
    bool initialized = false;
    SDL_Window* window = nullptr;
    SDL_Texture* texture = nullptr;
    SDL_Renderer* renderer = nullptr;
};
#endif
