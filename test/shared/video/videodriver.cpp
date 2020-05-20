#include <iostream>
#include <machine/video/videodriver.h>

void loadVideoRam(Memory* videoMemory) {
    for(uint16_t address = VideoDriver::VIDEO_MEM_BEGIN; address < VideoDriver::VIDEO_MEM_END; address++) {
        videoMemory->write(address, 0x0f);
    }
}

int main() {
    Memory memory;
    loadVideoRam(&memory);
    VideoDriver vd(&memory);
    vd.draw();
}
