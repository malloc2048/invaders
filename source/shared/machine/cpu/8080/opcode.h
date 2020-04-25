#ifndef NESEMU_OPCODE_H
#define NESEMU_OPCODE_H

#include <memory>
#include "flags.h"
#include "ram/ram.h"
#include "registers.h"

class OpCode {
public:
    OpCode() = default;
    ~OpCode() = default;

    // Returns the number of memory locations used in the instruction
    virtual int8_t Execute(uint8_t opcode) = 0;

protected:
    void updateFlags(uint8_t value);
    static uint8_t calculateParity(uint8_t value);
    void updateAuxiliaryCarry(uint8_t original, uint8_t updated);

    std::shared_ptr<RAM> ram;
    std::shared_ptr<Flags> flags;
    std::shared_ptr<Registers> registers;
};

void OpCode::updateFlags(uint8_t value) {
    flags->zero = value == 0x00 ? 1 : 0;
    flags->sign = value > 0x7f ? 1 : 0;
    flags->parity = calculateParity(value);
}

// return 1 when set bits is even
// return 0 when set bits is odd
uint8_t OpCode::calculateParity(uint8_t value) {
    uint8_t parity = 0;
    for(size_t idx = 0; idx < sizeof(value) * 8; idx++) {
        parity += ((value & (0x01u << idx)) > 0u) ? 1 : 0;
    }
    return parity & 0x01u ? 1 : 0;
}

// auxiliary carry flag is set when the upper 4 bits change after an addition (carry) or subtraction (borrow)
void OpCode::updateAuxiliaryCarry(uint8_t original, uint8_t updated) {
    flags->auxiliary = (original & 0xf0u) != (updated & 0xf0u) ? 1 : 0;
}

#endif
