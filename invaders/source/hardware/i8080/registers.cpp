#include "hardware/i8080/registers.h"

word hardware::Registers::readRegister(byte reg) const {
    word data = 0;
    switch(reg) {
        case common::B:
            return b;
        case common::C:
            return c;
        case common::D:
            return d;
        case common::E:
            return e;
        case common::H:
            return h;
        case common::L:
            return l;
        case common::M:
            return 0;
        case common::A:
            return accumulator;
        case common::BC:
            return word((b << 8u) | c);
        case common::DE:
            return word((d << 8u) | e);
        case common::HL:
            return word((h << 8u) | l);
        case common::SP:
            return stack_pointer;
        default:
            return data;
    }
}

void hardware::Registers::writeRegister(byte reg, word data) {
    switch(reg) {
        case common::B:
            b = data & 0xffu;
            break;
        case common::C:
            c = data & 0xffu;
            break;
        case common::D:
            d = data & 0xffu;
            break;
        case common::E:
            e = data & 0xffu;
            break;
        case common::H:
            h = data & 0xffu;
            break;
        case common::L:
            l = data & 0xffu;
            break;
        case common::A:
            accumulator = data & 0xffu;
            break;
        case common::BC:
            writeRegister(common::B, data >> 8u);
            writeRegister(common::C, data & 0xffu);
            break;
        case common::DE:
            writeRegister(common::D, data >> 8u);
            writeRegister(common::E, data & 0xffu);
            break;
        case common::HL:
            writeRegister(common::H, data >> 8u);
            writeRegister(common::L, data & 0xffu);
            break;
        case common::SP:
            stack_pointer = data;
            break;
        default:
            break;
    }
}
