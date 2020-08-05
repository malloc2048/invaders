#include "hardware/constants.h"

int hardware::FPS() { return 60; }
int hardware::SCREEN_WIDTH() { return 224; }
int hardware::SCREEN_HEIGHT() { return 256; }
word hardware::VRAM_ADDRESS() { return 0x2400; }
dword hardware::CYCLES_PER_FRAME() { return 2000000 / FPS(); }
std::string hardware::ROM_FILENAME() { return "../roms/invaders"; }
std::string hardware::ConfigFileName() { return "../roms/invaders.cfg"; }
dword hardware::HALF_CYCLES_PER_FRAME() { return CYCLES_PER_FRAME() / 2; }
std::string hardware::DISASSEMBLY_FILENAME() { return "../roms/invaders.dis"; }
std::string hardware::InstructionSetCSV() { return "../roms/instruction_set.csv"; }
