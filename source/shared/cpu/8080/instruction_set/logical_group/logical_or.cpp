#include "logical_group.h"

namespace logical_or {
    void ORA_A(Registers& registers) { registers.pc.d16 += 1; }
    void ORA_B(Registers& registers) { registers.pc.d16 += 1; }
    void ORA_C(Registers& registers) { registers.pc.d16 += 1; }
    void ORA_D(Registers& registers) { registers.pc.d16 += 1; }
    void ORA_E(Registers& registers) { registers.pc.d16 += 1; }
    void ORA_H(Registers& registers) { registers.pc.d16 += 1; }
    void ORA_L(Registers& registers) { registers.pc.d16 += 1; }
    void ORA_M(Registers& registers) { registers.pc.d16 += 1; }

    void ORI(Registers& registers) { registers.pc.d16 += 2; }
}
