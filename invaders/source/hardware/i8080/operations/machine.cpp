#include "hardware/i8080/operations/machine.h"

hardware::Machine::Machine(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {

}

void hardware::Machine::execute(byte opcode) {

}
