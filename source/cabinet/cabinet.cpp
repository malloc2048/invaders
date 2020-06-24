
#include "cabinet.h"

std::string cabinet::ROM_FILENAME() { return "../roms/invaders"; }
std::string cabinet::DISASSEMBLY_FILENAME() { return "../roms/invaders.dis"; }

int cabinet::FPS() { return 60; }
int cabinet::SCREEN_WIDTH() { return 224; }
int cabinet::SCREEN_HEIGHT() { return 256; }
uint16_t cabinet::VRAM_ADDRESS() { return 0x2400; }
uint32_t cabinet::CYCLES_PER_FRAME() { return 2000000 / FPS(); }
uint32_t cabinet::HALF_CYCLES_PER_FRAME() { return CYCLES_PER_FRAME() / 2; }

cabinet::Cabinet::Cabinet(): memory(), cpu(memory) {}
