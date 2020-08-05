#include "hardware/i8080/operations/arithmetic.h"

hardware::Arithmetic::Arithmetic(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {}

void hardware::Arithmetic::execute(byte opcode) {
    if((opcode & 0xf8u) == 0x80)                // ADD
        add(getData(opcode & 0x07u));
    else if(opcode >= 0x88 && opcode <= 0x8f)   // ADC
        add(getData(opcode & 0x07u) + (flags.carry ? 0x01 : 0x00));
    else if(opcode == 0xc6)                     // ADI
        add(nextByte());
    else if(opcode == 0xce)                     // ACI
        add(nextByte() + (flags.carry ? 0x01 : 0x00));
    else if(opcode >= 0x90 && opcode <= 0x97)   // SUB
        subtract(getData(opcode & 0x07u));
    else if(opcode >= 0x98 && opcode <= 0x9f)   // SBB
        subtract(getData(opcode & 0x07u) + (flags.carry ? 0x01 : 0x00));
    else if(opcode == 0xd6)                     // SUI
        subtract(nextByte());
    else if(opcode == 0xde)                     // SBI
        subtract(nextByte() + (flags.carry ? 0x01 : 0x00));
    else if((opcode & 0xC7u) == 0x04u)          // INR
        increment((opcode & 0x38u) >> 3u);
    else if((opcode & 0xCFu) == 0x03) {         // INX
        auto data = getData(((opcode & 0x30u) >> 4u) + BC) + 1;
        setData(((opcode & 0x30u) >> 4u) + BC, data);
    }
    else if((opcode & 0xc7u) == 0x05)           // DCR
        decrement((opcode & 0x38u) >> 3u);
    else if((opcode & 0xCFu) == 0x0b) {         // DCX
        auto data = getData(((opcode & 0x30u) >> 4u) + BC) - 1;
        setData(((opcode & 0x30u) >> 4u) + BC, data);
    }
    else if((opcode & 0xCFu) == 0x09)          // DAD
        dad(((opcode & 0x30u) >> 4u) + BC);
    else if(opcode == 0x27)                    // DAA
        daa();
}

void hardware::Arithmetic::add(byte data) {
    word sum = data + registers.accumulator;

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
    word value = getData(dst) + 1;

    flags.zero = (value & 0xffu) == 0;
    flags.sign = (value & 0xffu) > 0x007fu;
    flags.calculateParity(value);
    flags.half_carry = (registers.accumulator & 0x0fu) > (value & 0x000fu);
    setData(dst, value);
}

void hardware::Arithmetic::decrement(byte dst) {
    byte value = getData(dst) - 1;

    flags.zero = (value & 0xffu) == 0;
    flags.sign = (value & 0xffu) > 0x007fu;
    flags.calculateParity(value);
    flags.half_carry = (value & 0x0fu) == 0x000fu;
    setData(dst, value);
}

void hardware::Arithmetic::dad(byte src) {
    word sum = getData(src) + getData(HL);
    flags.carry = (sum & 0x10000u) != 0;
    setData(HL, sum);
}

void hardware::Arithmetic::daa() {
    byte lsb = registers.accumulator & 0x0fu;

    if(flags.half_carry || lsb > 9) {
        registers.accumulator += 6;
    }

    byte msb = registers.accumulator >> 4u;
    if(flags.carry || msb > 9) {
        msb += 6;
        registers.accumulator &= 0x0fu;
        registers.accumulator |= msb << 0x04u;
    }

    flags.zero = (registers.accumulator & 0xffu) == 0;
    flags.sign = (registers.accumulator & 0xffu) > 0x007fu;
    flags.calculateParity(registers.accumulator);
    flags.half_carry = (lsb & 0x10u) != 0;
    flags.carry = msb > 9;
}
