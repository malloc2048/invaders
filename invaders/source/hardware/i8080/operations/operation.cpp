#include "hardware/i8080/operations/operation.h"

hardware::Operation::Operation(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers) :
    flags(flags), memory(memory), registers(registers){}

word hardware::Operation::getData(byte src) const {
    switch(src) {
        case common::B:
            return registers.b;
        case common::C:
            return registers.c;
        case common::D:
            return registers.d;
        case common::E:
            return registers.e;
        case common::H:
            return registers.h;
        case common::L:
            return registers.l;
        case common::M:
            return memory.read_byte(registers.readRegister(common::HL));
        case common::A:
            return registers.accumulator;
        case common::BC:
            return (registers.b << 8u) | registers.c;
        case common::DE:
            return (registers.d << 8u) | registers.e;
        case common::HL:
            return (registers.h << 8u) | registers.l;
        case common::SP:
            return registers.stack_pointer;
        default:
            return 0;
    }
}

byte hardware::Operation::nextByte() const {
    return memory.read_byte(registers.program_counter++);
}

word hardware::Operation::nextWord() const {
    auto data = memory.read_word(registers.program_counter);
    registers.program_counter += 2;
    return data;
}

void hardware::Operation::setData(byte dst, word data) {
    switch(dst) {
        case common::B:
            registers.b = data;
            break;
        case common::C:
            registers.c = data;
            break;
        case common::D:
            registers.d = data;
            break;
        case common::E:
            registers.e = data;
            break;
        case common::H:
            registers.h = data;
            break;
        case common::L:
            registers.l = data;
            break;
        case common::M:
            memory.write(registers.readRegister(common::HL), data);
            break;
        case common::A:
            registers.accumulator = data;
            break;
        case common::BC:
            registers.b = (data & 0xff00u) >> 0x08u;
            registers.c = data & 0xffu;
            break;
        case common::DE:
            registers.d = (data & 0xff00u) >> 0x08u;
            registers.e = data & 0xffu;
            break;
        case common::HL:
            registers.h = (data & 0xff00u) >> 0x08u;
            registers.l = data & 0xffu;
            break;
        case common::SP:
            registers.stack_pointer = data;
            break;
        default:
            return;
    }
}
