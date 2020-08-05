#include "hardware/i8080/registers.h"

word hardware::Registers::readRegister(byte reg) const {
    word data = 0;
    switch(reg) {
        case B:
            return b;
        case C:
            return c;
        case D:
            return d;
        case E:
            return e;
        case H:
            return h;
        case L:
            return l;
        case M:
            return 0;
        case A:
            return accumulator;
        case BC:
            return word((b << 8u) | c);
        case DE:
            return word((d << 8u) | e);
        case HL:
            return word((h << 8u) | l);
        case SP:
            return stack_pointer;
        default:
            return data;
    }
    return data;
}

word hardware::Registers::readRegisterPair(byte regPair) const {
    word data = 0;
    switch(regPair) {
        case 0x00:
            data = (b << 8u) | c;
            break;
        case 0x01:
            data = (d << 8u) | e;
            break;
        case 0x02:
            data = (h << 8u) | l;
            break;
        case 0x03:
            data = stack_pointer;
            break;
        default:
            data = 0;
    }
    return data;
}
