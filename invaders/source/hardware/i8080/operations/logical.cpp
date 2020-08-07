#include "hardware/i8080/operations/logical.h"

hardware::Logical::Logical(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {

}

void hardware::Logical::execute(byte opcode) {
    if ((opcode & 0xf8u) == 0xa0) {          // ANA
        ana(getData(opcode & 0x07u));
    } else if (opcode == 0xe6) {               // ANI
        ana(nextByte());
        flags.half_carry = false;
    } else if ((opcode & 0xf8u) == 0xa8) {     // XRA
        xra(getData(opcode & 0x07u));
    } else if (opcode == 0xeeu)                 // XRI
        xra(nextByte());
    else if ((opcode & 0xf8u) == 0xb0)        // ORA
        ora(getData(opcode & 0x07u));
    else if (opcode == 0xf6)                  // ORI
        ora(nextByte());
    else if ((opcode & 0xf8u) == 0xb8)        // CMP
        compare(getData(opcode & 0x07u));
    else if (opcode == 0xfeu)                // CPI
        compare(nextByte());
    else if (opcode == 0x07u) {               // RLC
        flags.carry = registers.accumulator >> 7u;
        registers.accumulator = (registers.accumulator << 0x01u) | (flags.carry ? 0x01 : 0x00);
    } else if (opcode == 0x0fu) {                // RRC
        flags.carry = registers.accumulator & 0x01u;
        registers.accumulator = (registers.accumulator >> 0x01u) | (flags.carry ? 0x80u : 0x00);
    } else if(opcode == 0x17u) {                 // RAL
        byte carry = flags.carry ? 0x01u : 0x00;
        flags.carry = registers.accumulator >> 7u;
        registers.accumulator = (registers.accumulator << 1u) | carry;
    } else if(opcode == 0x1fu) {               // RAR
        byte carry = flags.carry ? 0x80u : 0x00;
        flags.carry = registers.accumulator & 1u;
        registers.accumulator = (registers.accumulator >> 1u) | carry;
    }
    else if(opcode == 0x2fu)                 // CMA
        registers.accumulator ^= 0xffu;
    else if(opcode == 0x3fu)                 // CMC
        flags.carry = !flags.carry;
    else if(opcode == 0x37u)                 // STC
        flags.carry = true;
}

void hardware::Logical::ana(byte data) {
    const byte accumulator = registers.accumulator;
    registers.accumulator &= data;

    flags.zero = registers.accumulator == 0;
    flags.sign = registers.accumulator > 0x7fu;
    flags.calculateParity(registers.accumulator);
    flags.carry = false;
    flags.half_carry = ((registers.accumulator | accumulator) & 0x08u) != 0;
}

void hardware::Logical::xra(byte data) {
    word result = registers.accumulator ^ data;

    flags.zero = result == 0;
    flags.sign = result > 0x7fu;
    flags.calculateParity(result);
    flags.carry = false;
    flags.half_carry = false;
    registers.accumulator = result & 0x00ffu;
}

void hardware::Logical::ora(byte data) {
    word result = registers.accumulator | data;

    flags.zero = result == 0;
    flags.sign = result > 0x7fu;
    flags.calculateParity(result);
    flags.carry = false;
    flags.half_carry = false;
    registers.accumulator = result & 0x00ffu;
}

void hardware::Logical::compare(byte data) {
    word result = registers.accumulator - data;

    flags.zero = result == 0;
    flags.sign = (result & 0x00ff) > 0x7fu;
    flags.calculateParity(result);
    flags.carry = (result & 0x0100u) != 0;
    flags.half_carry = (result & 0x000fu) > (registers.accumulator & 0x0fu);
}
