#include "hardware/i8080/operations/operation.h"

hardware::Operation::Operation(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers) :
    flags(flags), memory(memory), registers(registers){}

byte hardware::Operation::getData(byte src) const {
    switch(src) {
        case 0x00:
            return registers.b;
        case 0x01:
            return registers.c;
        case 0x02:
            return registers.d;
        case 0x03:
            return registers.e;
        case 0x04:
            return registers.h;
        case 0x05:
            return registers.l;
        case 0x06:
            return memory.read_byte(registers.readRegisterPair(0x02));
        case 0x07:
            return registers.accumulator;
        default:
            return 0;
    }
}

byte hardware::Operation::nextByte() const {
    return memory.read_byte(registers.program_counter++);
}

void hardware::Operation::setData(byte src, byte data) {
    switch(src) {
        case 0x00:
            registers.b = data;
        case 0x01:
            registers.c = data;
        case 0x02:
            registers.d = data;
        case 0x03:
            registers.e = data;
        case 0x04:
            registers.h = data;
        case 0x05:
            registers.l = data;
        case 0x06:
            memory.write(registers.readRegisterPair(0x02), data);
        case 0x07:
            registers.accumulator = data;
        default:
            return;
    }
}
