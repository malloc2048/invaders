#include <bitset>
#include <iostream>
#include "videodriver.h"

VideoDriver::VideoDriver(RAM* mem): memory(mem), window(sf::VideoMode(512, 448), "Space Invaders") {

}

void VideoDriver::draw() {
    sf::Clock clock;
    sf::Event event{};

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::EventType::Closed: window.close(); break;
                case sf::Event::EventType::KeyPressed: handleKeyPress(event); break;
                default: break;
            }
        }

        if(clock.getElapsedTime().asSeconds() >= (1.0 / 60.0)) {
//            generateInterrupt(0x02);
            clock.restart();
            updateScreenBuffer();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

void VideoDriver::updateScreenBuffer() {
    int pixelIdx = 0;
    uint32_t pixels[256 * 224];

    for(auto address = VIDEO_MEM_BEGIN; address < VIDEO_MEM_END; address++) {
        if(address == VIDEO_MEM_BEGIN + 128) {
//            generateInterrupt(0x01);
        }

        std::bitset<8> byte(memory->read(address));
        for(int idx = 0; idx < 8; idx++) {
            pixels[pixelIdx] = byte[idx] == 1 ? 0xffffffff : 0x000000ff;
            pixelIdx++;
        }
    }

    screen.create(256, 224, (uint8_t*)pixels);
    texture.loadFromImage(screen);
    sprite.setTexture(texture);

    sprite.setRotation(-90.0f);
    sprite.setOrigin(256.0f, 112.0f);
    sprite.setPosition(256.0f, 112.0f);

}

void VideoDriver::setInterruptGenerateFunction(std::function<void(uint8_t)> interruptFunc) {
    generateInterrupt = std::move(interruptFunc);
}

void VideoDriver::handleKeyPress(sf::Event& event) {
    switch(event.key.code) {
        case sf::Keyboard::R:
            std::cout << "Restart" << std::endl;
            generateInterrupt(0);
            break;
        case sf::Keyboard::Escape:
            window.close();
            break;
        default: break;
    }
}
