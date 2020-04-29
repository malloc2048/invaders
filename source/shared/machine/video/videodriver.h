#ifndef NESEMU_VIDEODRIVER_H
#define NESEMU_VIDEODRIVER_H

#include <SFML/Graphics.hpp>
#include "machine/ram/ram.h"

class VideoDriver {
public:
    explicit VideoDriver(RAM* mem);
    ~VideoDriver() = default;

    void draw();
    void updateScreenBuffer();

    static const uint16_t VIDEO_MEM_BEGIN = 0x2400;
    static const uint16_t VIDEO_MEM_END = 0x4000;
    static const uint16_t VIDEO_MEM_SIZE = 0x1c00;

private:
    RAM* memory;
    sf::Image screen;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RenderWindow window;
};
#endif
