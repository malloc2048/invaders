#ifndef NESEMU_RST_H
#define NESEMU_RST_H

#include "cpu/8080/opcode.h"

class RST: public OpCode {
public:
    RST() = delete;
    ~RST() = default;
    RST(std::shared_ptr<RAM> ram, std::shared_ptr<Flags> flags, std::shared_ptr<Registers> registers) {
        ram = ram;
        flags = flags;
        registers = registers;
    }

    int8_t Execute(uint8_t opcode) override {
        uint8_t number = (opcode & 0x038u) >> 3u;

        RegisterPair nextAddr{};
        nextAddr.d16 = registers->pc.d16 + 1;
        ram->write(registers->sp.d16 - 1, nextAddr.bytes.high);
        ram->write(registers->sp.d16 - 2, nextAddr.bytes.low);
        registers->sp.d16 -= 2;
        registers->pc.d16 = 8 * number;

        return 0;
    }

protected:
    void ret() {
        RegisterPair address{};
        address.bytes.low = ram->read(registers->sp.d16);
        address.bytes.high = ram->read(registers->sp.d16 + 1);
        registers->pc.d16 = address.d16;
        registers->sp.d16 += 2;
    }
};

#endif
