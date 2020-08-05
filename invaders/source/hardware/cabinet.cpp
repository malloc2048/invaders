
#include "hardware/cabinet.h"

hardware::Cabinet::Cabinet(): memory(), cpu(memory) {
    cpu.loadInstructionSet();
}

word hardware::Cabinet::getPC() const {
    return cpu.registers.program_counter;
}

qword hardware::Cabinet::getCycleCount() const {
    return cpu.cycles;
}

void hardware::Cabinet::interrupt(word address) {
    if(cpu.flags.interruptEnabled) {
        cpu.flags.interruptEnabled = false;

        // PUSH current PC to stack
        cpu.registers.stack_pointer -= 2;
        memory.write_word(cpu.registers.stack_pointer, cpu.registers.program_counter);

        cpu.registers.program_counter = address;
        cpu.cycles += 11;
    }
}

void hardware::Cabinet::setCycleCount(word count) {
    cpu.cycles = count;
}

byte hardware::Cabinet::getAccumulator() const {
    return cpu.registers.accumulator;
}

void hardware::Cabinet::setAccumulator(byte value) {
    cpu.registers.accumulator = value;
}

void hardware::Cabinet::incrementPC(byte increment) {
    cpu.registers.program_counter += increment;
}
