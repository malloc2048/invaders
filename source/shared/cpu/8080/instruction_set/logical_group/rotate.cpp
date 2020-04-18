#include "logical_group.h"

namespace rotate {
    void RLC(Registers& registers) { registers.pc.d16 += 1; }
    void RRC(Registers& registers) { registers.pc.d16 += 1; }
    void RAL(Registers& registers) { registers.pc.d16 += 1; }
    void RAR(Registers& registers) { registers.pc.d16 += 1; }
}
