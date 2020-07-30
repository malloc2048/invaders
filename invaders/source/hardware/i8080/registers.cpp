#include "hardware/i8080/registers.h"

byte hardware::Registers::readRegister(byte reg) const {
    switch(reg) {
        case 0x00:
            return b;
        case 0x01:
            return c;
        case 0x02:
            return d;
        case 0x03:
            return e;
        case 0x04:
            return h;
        case 0x05:
            return l;
        case 0x06:
            return 0;
        case 0x07:
            return accumulator;
        default:
            return 0;
    }
}

word hardware::Registers::readRegisterPair(byte regPair) const {
    switch(regPair) {
        case 0x00:
            return (b << 8u) | c;
        case 0x01:
            return (d << 8u) | e;
        case 0x02:
            return (h << 8u) | l;
        case 0x03:
            return stack_pointer;
    }
    return 0;
}
