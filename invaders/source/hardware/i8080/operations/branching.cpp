#include "hardware/i8080/operations/branching.h"

hardware::Branching::Branching(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {
}

void hardware::Branching::execute(byte opcode) {
    if(opcode  == 0xc3u) // Jump
        registers.program_counter = nextWord();
    else if((opcode & 0xc7u) == 0xc2u) { // Conditional Jump
        auto address = nextWord();
        if (checkCondition((opcode & 0x38u) >> 0x03u))
            registers.program_counter = address;
    }
    else if(opcode  == 0xcdu) // Call
        call();
    else if((opcode & 0xc7u) == 0xc4u) { // Conditional Call
        if (checkCondition((opcode & 0x38u) >> 0x03u))
            call();
        else
            registers.program_counter += 2;
    } else if(opcode  == 0xc9u) // RET
        ret();
    else if((opcode & 0xc7u) == 0xc0u) { // Conditional Ret
        if (checkCondition((opcode & 0x38u) >> 0x03u))
            ret();
    } else if((opcode & 0xc7u) == 0xc7u) { // RST
        restart((opcode & 0x038u) >> 3u);
    } else if(opcode == 0xe9u)  // PCHL
        registers.program_counter = registers.readRegister(HL);
}

void hardware::Branching::ret() {
    registers.program_counter = memory.read_word(registers.stack_pointer);
    registers.stack_pointer += 2;
}

void hardware::Branching::call() {
    auto address = nextWord();
    registers.stack_pointer -= 2;
    memory.write_word(registers.stack_pointer, registers.program_counter);
    registers.program_counter = address;
}

#include <iostream>
void hardware::Branching::restart(byte restartNum) {
    registers.stack_pointer -= 2;
    memory.write_word(registers.stack_pointer, registers.program_counter);
    registers.program_counter = 8 * restartNum;
}

bool hardware::Branching::checkCondition(byte condition) {
    switch(condition) {
        case 0x00:
            return !flags.zero;
        case 0x01:
            return flags.zero;
        case 0x02:
            return !flags.carry;
        case 0x03:
            return flags.carry;
        case 0x04:
            return !flags.parity;
        case 0x05:
            return flags.parity;
        case 0x06:
            return !flags.sign;
        case 0x07:
            return flags.sign;
        default:
            return false;
    }
}
