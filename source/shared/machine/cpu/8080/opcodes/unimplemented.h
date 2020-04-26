#ifndef NESEMU_Unimplemented_H
#define NESEMU_Unimplemented_H

#include "cpu/8080/opcode.h"

class Unimplemented: public OpCode {
public:
    Unimplemented() = delete;
    ~Unimplemented() = default;
    Unimplemented(RAM* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode) override {
        // TODO: add a log entry here?
        exit(-1);
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << " \tUNKNOWN";
        registers->pc.d16 += 1;
    }
};
#endif
