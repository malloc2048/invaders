#ifndef NESEMU_VIDEODRIVER_H
#define NESEMU_VIDEODRIVER_H

#include "machine/ram/ram.h"

class VideoDriver {
public:
    explicit VideoDriver(RAM* mem);
    ~VideoDriver() = default;

    void Draw();

private:
    static const uint16_t VIDEO_MEM_BEGIN = 0x2400;
    static const uint16_t VIDEO_MEM_END = 0x3fff;

    RAM* memory;
};
#endif
