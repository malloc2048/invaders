#include <bitset>
#include <iostream>
#include "videodriver.h"

VideoDriver::VideoDriver(RAM* mem): memory(mem), window(sf::VideoMode(256, 224), "Space Invaders") {

}

void VideoDriver::draw() {
    sf::Clock clock;
    sf::Event event{};
    sf::CircleShape circle(200);
    circle.setFillColor(sf::Color::Cyan);

//    screen.create(256, 224, pixels);
//    texture.loadFromImage(screen);
//    sprite.setTexture(texture);

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::EventType::Closed: window.close(); break;
                default: break;
            }
        }
        updateScreenBuffer();

//        if(clock.getElapsedTime().asSeconds() >= 5) {
//            clock.restart();
//            updateScreenBuffer();
//        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

void VideoDriver::updateScreenBuffer() {
    int pixelIdx = 0;
    uint32_t pixels[256 * 224];

    for(auto address = VIDEO_MEM_BEGIN; address < VIDEO_MEM_END; address++) {
        std::bitset<8> byte(memory->read(address));
        for(int idx = 0; idx < 8; idx++) {
            pixels[pixelIdx] = byte[idx] == 1 ?0xffffffff : 0x000000ff;
            pixelIdx++;
        }
    }

    screen.create(256, 224, (uint8_t*)pixels);
    texture.loadFromImage(screen);
    sprite.setTexture(texture);
}
