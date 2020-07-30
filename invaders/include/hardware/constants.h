#ifndef INVADERS_CONSTANTS_H
#define INVADERS_CONSTANTS_H

#include <string>

typedef unsigned char byte ;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned long qword;

namespace hardware {
    int FPS();
    int SCREEN_WIDTH();
    int SCREEN_HEIGHT();
    word VRAM_ADDRESS();
    dword CYCLES_PER_FRAME();
    std::string ROM_FILENAME();
    dword HALF_CYCLES_PER_FRAME();
    std::string InstructionSetCSV();
    std::string DISASSEMBLY_FILENAME();
}
#endif
