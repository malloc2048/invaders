#ifndef EMULATOR_VIDEODRIVER_H
#define EMULATOR_VIDEODRIVER_H

#include <functional>
#include <SFML/Graphics.hpp>
#include "machine/memory/memory.h"

class VideoDriver {
public:
    explicit VideoDriver(Memory* mem);
    ~VideoDriver() = default;

    void draw();
    void updateScreenBuffer();
    void setInterruptGenerateFunction(std::function<void(uint8_t)> interruptFunc);

    static const uint16_t VIDEO_MEM_BEGIN = 0x2400;
    static const uint16_t VIDEO_MEM_END = 0x4000;
    static const uint16_t VIDEO_MEM_SIZE = 0x1c00;

protected:
    void handleKeyPress(sf::Event& event);

private:
    Memory* memory;
    sf::Image screen;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RenderWindow window;

    std::function<void(uint8_t)> generateInterrupt;
};
#endif
