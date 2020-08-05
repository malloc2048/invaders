#include "hardware/i8080/operations/operation.h"

hardware::Operation::Operation(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers) :
    flags(flags), memory(memory), registers(registers){}

word hardware::Operation::getData(byte src) const {
    switch(src) {
        case B:
            return registers.b;
        case C:
            return registers.c;
        case D:
            return registers.d;
        case E:
            return registers.e;
        case H:
            return registers.h;
        case L:
            return registers.l;
        case M:
            return memory.read_byte(registers.readRegister(HL));
        case A:
            return registers.accumulator;
        case BC:
            return (registers.b << 8u) | registers.c;
        case DE:
            return (registers.d << 8u) | registers.e;
        case HL:
            return (registers.h << 8u) | registers.l;
        case SP:
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
        case B:
            registers.b = data;
            break;
        case C:
            registers.c = data;
            break;
        case D:
            registers.d = data;
            break;
        case E:
            registers.e = data;
            break;
        case H:
            registers.h = data;
            break;
        case L:
            registers.l = data;
            break;
        case M:
            memory.write(registers.readRegister(HL), data);
            break;
        case A:
            registers.accumulator = data;
            break;
        case BC:
            registers.b = (data & 0xff00u) >> 0x08u;
            registers.c = data & 0xffu;
            break;
        case DE:
            registers.d = (data & 0xff00u) >> 0x08u;
            registers.e = data & 0xffu;
            break;
        case HL:
            registers.h = (data & 0xff00u) >> 0x08u;
            registers.l = data & 0xffu;
            break;
        case SP:
            registers.stack_pointer = data;
            break;
        default:
            return;
    }
}
