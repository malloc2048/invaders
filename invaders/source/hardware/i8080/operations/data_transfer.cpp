#include "hardware/i8080/operations/data_transfer.h"

hardware::DataTransfer::DataTransfer(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {

}

void hardware::DataTransfer::execute(byte opcode) {

}
