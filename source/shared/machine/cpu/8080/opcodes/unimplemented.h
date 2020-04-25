#ifndef NESEMU_Unimplemented_H
#define NESEMU_Unimplemented_H

#include "cpu/8080/opcode.h"

class Unimplemented: public OpCode {
public:
    Unimplemented() = delete;
    ~Unimplemented() = default;
    Unimplemented(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        // TODO: add a log entry here?
        exit(-1);
    }
};
#endif
