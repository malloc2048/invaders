#include "opcode.h"

std::string OpCode::registerPairNames[4] = { "B", "D", "H", "SP" };
std::string OpCode::registerNames[8] = { "B", "C", "D", "E", "H", "L", "M", "A" };
std::string OpCode::conditionStr[8] = { "NZ", "Z", "NC", "C", "PO", "PE", "P", "M" };

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
    return parity & 0x01u ? 0 : 1;
}

// auxiliary carry flag is set when the upper 4 bits change after an addition (carry) or subtraction (borrow)
void OpCode::updateCarry(uint8_t original, uint8_t updated) {
    uint16_t result = original + updated;
    uint16_t carry = result ^ original ^ updated;

    flags->halfCarry = (carry & 0x0010) >> 4;
    flags->carry = (carry & 0x0100) >> 8;
}
