#include "ram.h"

uint8_t RAM::read(uint16_t) const {
    return 0;
}

bool RAM::write(uint16_t address, uint8_t value) {
    return false;
}
