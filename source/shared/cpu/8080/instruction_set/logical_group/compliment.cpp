#include "logical_group.h"

namespace compliment {
    void CMA(Registers& registers) { registers.pc.d16 += 1; }
    void CMC(Registers& registers) { registers.pc.d16 += 1; }
    void STC(Registers& registers) { registers.pc.d16 += 1; }
}
