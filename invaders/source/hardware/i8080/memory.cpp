#include "hardware/i8080/memory.h"

byte hardware::Memory::read_byte(word address) const {
    return memory[address];
}

void hardware::Memory::write(word address, byte value) {
    if (address >= ROM_SIZE) {
        memory[address] = value;
    } else {
        fprintf(stdout, "attempt to write to ROM %04x\n", address);
    }
}
