#include "common/constants.h"

int common::FPS() { return 60; }
int common::SCREEN_WIDTH() { return 224; }
int common::SCREEN_HEIGHT() { return 256; }
word common::VRAM_ADDRESS() { return 0x2400; }
dword common::CYCLES_PER_FRAME() { return 2000000 / FPS(); }
//std::string common::ROM_FILENAME() { return "../roms/invaders"; }
//std::string common::LogFileName() { return "../roms/invaders.log"; }
//std::string common::ErrorLogFileName() { return "../roms/error.log"; }
std::string common::ConfigFileName() { return "../roms/invaders.cfg"; }
dword common::HALF_CYCLES_PER_FRAME() { return CYCLES_PER_FRAME() / 2; }
//std::string common::DISASSEMBLY_FILENAME() { return "../roms/invaders.dis"; }
//std::string common::InstructionSetCSV() { return "../roms/instruction_set.csv"; }
