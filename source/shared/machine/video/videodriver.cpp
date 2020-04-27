#include <bitset>
#include <iostream>
#include "videodriver.h"

VideoDriver::VideoDriver(RAM* mem): memory(mem) {}

void VideoDriver::Draw() {
    for(size_t idx = 0; idx < VIDEO_MEM_END; idx++) {
        std::bitset<8> byte(memory->read(VIDEO_MEM_BEGIN + idx));
        std::cout << byte;

        if(idx == 0 || idx % 32)
            std::cout << " ";
        else
            std::cout << std::endl;
    }
}
