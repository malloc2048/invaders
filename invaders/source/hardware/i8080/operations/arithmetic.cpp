#include "hardware/i8080/operations/arithmetic.h"

hardware::Arithmetic::Arithmetic(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {}

void hardware::Arithmetic::execute(byte opcode) {
    auto src = opcode & 0x07u;
    auto data = getData(src);

    if(opcode >= 0x80 && opcode <= 0x87)
        add(data);
    else if(opcode >= 0x88 && opcode <= 0x8f)
        add(data + (flags.carry ? 0x01 : 0x00));
    else if(opcode == 0xc6)
        add(nextByte());
    else if(opcode == 0xce)
        add(nextByte() + (flags.carry ? 0x01 : 0x00));
    else if(opcode >= 0x90 && opcode <= 0x97)
        subtract(data);
    else if(opcode >= 0x98 && opcode <= 0x9f)
        subtract(data + (flags.carry ? 0x01 : 0x00));
    else if(opcode == 0xd6)
        subtract(nextByte());
    else if(opcode == 0xde)
        subtract(nextByte() + (flags.carry ? 0x01 : 0x00));
    else if(isIncrement(opcode))
        increment((opcode & 0x38u) >> 3u);
}

void hardware::Arithmetic::add(byte data) {
    word sum = data + registers.accumulator;

    // use the original a value to calculate half carry
    flags.zero = (sum & 0xffu) == 0;
    flags.sign = (sum & 0xffu) > 0x007fu;
    flags.calculateParity(sum);
    flags.carry = (sum & 0x100u) != 0;
    flags.half_carry = (registers.accumulator & 0x0fu) > (sum & 0x000fu);

    registers.accumulator = sum & 0x00ffu;
}

void hardware::Arithmetic::subtract(byte data) {
    word diff = registers.accumulator - data;

    flags.half_carry = (diff & 0x000fu) > (registers.accumulator & 0x0fu);
    flags.zero = (diff & 0xffu) == 0;
    flags.sign = (diff & 0xffu) > 0x007fu;
    flags.calculateParity(diff);
    flags.carry = (diff & 0x100u) != 0;

    registers.accumulator = diff & 0x00ffu;
}

void hardware::Arithmetic::increment(byte dst) {
    setData(dst, getData(dst));

}

bool hardware::Arithmetic::isIncrement(byte opcode) {
    return false;
}
