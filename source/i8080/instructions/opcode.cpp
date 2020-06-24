#include "opcode.h"

Instruction::Instruction(Flags& flags, Memory& memory, Registers& registers):
    flags(flags), memory(memory), registers(registers) {}

void Instruction::updateFlags(uint8_t value) {
    flags.zero = value == 0x00 ? 1 : 0;
    flags.sign = value > 0x7f ? 1 : 0;
    flags.parity = calculateParity(value);
}

// return 1 when set bits is even
// return 0 when set bits is odd
uint8_t Instruction::calculateParity(uint8_t value) {
    uint8_t parity = 0;
    for(size_t idx = 0; idx < sizeof(value) * 8; idx++) {
        parity += ((value & (0x01u << idx)) > 0u) ? 1 : 0;
    }
    return parity & 0x01u ? 0 : 1;
}

// auxiliary carry flag is set when the upper 4 bits change after an addition (carry) or subtraction (borrow)
void Instruction::updateCarry(uint8_t original, uint8_t updated) {
    uint16_t result = original + updated;
    uint16_t carry = result ^ original ^ updated;

    flags.halfCarry = (carry & 0x0010u) >> 4u;
    flags.carry = (carry & 0x0100u) >> 8u;
}
