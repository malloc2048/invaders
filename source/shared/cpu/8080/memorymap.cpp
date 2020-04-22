#include "memorymap.h"
#include "common/config.h"

const uint16_t MemoryMap::ROM_MIN_ADDRESS = 0x0000;
const uint16_t MemoryMap::ROM_MAX_ADDRESS = 0x1fff;
const uint16_t MemoryMap::RAM_MIN_ADDRESS = 0x2000;
const uint16_t MemoryMap::RAM_MAX_ADDRESS = 0x23ff;
const uint16_t MemoryMap::VIDEO_RAM_MIN_ADDRESS = 0x2400;
const uint16_t MemoryMap::VIDEO_RAM_MAX_ADDRESS = 0x27ff;

bool MemoryMap::Write(uint16_t address, uint8_t value) {
    if(address > ROM_MAX_ADDRESS) {
        memory[address] = value;
        return true;
    }

    fprintf(TraceOut(), "error: attempt to write to ROM %04x", address);
    return false;
}
