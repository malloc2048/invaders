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
            return memory.read_byte(registers.readRegisterPair(0x02));
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

void hardware::Operation::setData(byte dst, word data) {
    switch(dst) {
        case B:
            registers.b = data;
        case C:
            registers.c = data;
        case D:
            registers.d = data;
        case E:
            registers.e = data;
        case H:
            registers.h = data;
        case L:
            registers.l = data;
        case M:
            memory.write(registers.readRegisterPair(0x02), data);
        case A:
            registers.accumulator = data;
        case BC:
            registers.b = (data & 0xffu) >> 0x08u;
            registers.c = data & 0xffu;
        case DE:
            registers.d = (data & 0xffu) >> 0x08u;
            registers.e = data & 0xffu;
        case HL:
            registers.h = (data & 0xffu) >> 0x08u;
            registers.l = data & 0xffu;
        case SP:
        default:
            return;
    }
}
