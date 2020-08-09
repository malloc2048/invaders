#include "hardware/i8080/operations/machine.h"

hardware::Machine::Machine(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {}

void hardware::Machine::execute(byte opcode) {
    if(opcode == 0xf5u) // PUSH PSW
        push(getPSW());
    else if((opcode & 0xcfu) == 0xc5u) // PUSH
        push(getData(((opcode & 0x30u) >> 0x04u) + common::BC));
    else if(opcode == 0xf1u) // POP PSW
        setPSW();
    else if((opcode & 0xcfu) == 0xc1u) // POP
        pop(((opcode & 0x30u) >> 0x04u) + common::BC);
    else if(opcode == 0xe3u)
        xthl();
    else if(opcode == 0xf9u)    // SPHL
        registers.stack_pointer = getData(common::HL);
    else if(opcode == 0xfbu)  // EI
        flags.interruptEnabled = true;
    else if(opcode == 0xf3u)  // DI
        flags.interruptEnabled = false;
    else if(opcode == 0x76u)  // HLT
        flags.halted = true;

    // NOTE: NOP does nothing, IN and OUT ar handled at a higher level where access to I/O is more convenient
}

void hardware::Machine::push(word data) {
    registers.stack_pointer -= 2;
    memory.write_word(registers.stack_pointer, data);
}

word hardware::Machine::getPSW() const {
    word psw = registers.accumulator << 8u;
    psw &= 0xff00u;

    psw |= flags.zero ? 0x01u : 0x00u;
    psw |= flags.sign ? 0x02u : 0x00u;
    psw |= flags.parity ? 0x04u : 0x00u;
    psw |= flags.carry ? 0x08u : 0x00u;
    psw |= flags.half_carry ? 0x10u : 0x00u;

    return psw;
}

void hardware::Machine::pop(byte dst) {
    word data = memory.read_word(registers.stack_pointer);
    setData(dst, data);
    registers.stack_pointer += 2;
}

void hardware::Machine::setPSW() {
    auto psw = memory.read_word(registers.stack_pointer);
    registers.stack_pointer += 2;

    registers.accumulator = psw >> 0x08u;
    flags.zero = psw & 0x01u;
    flags.sign = psw & 0x02u;
    flags.parity = psw & 0x04u;
    flags.carry = psw & 0x08u;
    flags.half_carry = psw & 0x10u;
}

void hardware::Machine::xthl() {
    auto sp = memory.read_word(registers.stack_pointer);
    memory.write_word(registers.stack_pointer, getData(common::HL));
    setData(common::HL, sp);
}
