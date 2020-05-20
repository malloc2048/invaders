#ifndef EMULATOR_Unimplemented_H
#define EMULATOR_Unimplemented_H

#include "machine/cpu/8080/opcode.h"

class Unimplemented: public OpCode {
public:
    Unimplemented() = delete;
    ~Unimplemented() = default;
    Unimplemented(Memory* ramIn, Flags* flagsIn, Registers* registersIn) {
        ram = ramIn;
        flags = flagsIn;
        registers = registersIn;
    }

    int8_t Execute(uint8_t opcode,std::ostream& debug) override {
        // TODO: add a log entry here?
        std::cout << "shit broke again: " << std::hex << (unsigned)registers->pc.d16 << std::endl;
        exit(-1);
    }

    void Disassemble(std::ostream& out) override {
        out << std::hex << std::setw(2) << std::setfill('0');
        out << (unsigned)ram->read(registers->pc.d16) << " \tUNKNOWN";
        registers->pc.d16 += 1;
    }
};
#endif
