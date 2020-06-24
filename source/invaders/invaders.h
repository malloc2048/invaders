#ifndef INVADERS_INVADERS_H
#define INVADERS_INVADERS_H

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include "cabinet/cabinet.h"

class Invaders {
public:
    explicit Invaders(cabinet::Cabinet& cabinet);
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
    void handleKeyUp(SDL_Scancode keyCode);
    void handleKeyDown(SDL_Scancode keyCode);

private:
    cabinet::Cabinet& cabinet;
    uint32_t timer = 0;
    bool shouldQuit = false;
    bool initialized = false;

    SDL_Window* window = nullptr;
    SDL_Texture* texture = nullptr;
    SDL_Renderer* renderer = nullptr;
};
#endif
