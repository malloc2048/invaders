#include "logical_group.h"

namespace logical_xor {
    void XRA_A(Registers& registers) { registers.pc.d16 += 1; }
    void XRA_B(Registers& registers) { registers.pc.d16 += 1; }
    void XRA_C(Registers& registers) { registers.pc.d16 += 1; }
    void XRA_D(Registers& registers) { registers.pc.d16 += 1; }
    void XRA_E(Registers& registers) { registers.pc.d16 += 1; }
    void XRA_H(Registers& registers) { registers.pc.d16 += 1; }
    void XRA_L(Registers& registers) { registers.pc.d16 += 1; }
    void XRA_M(Registers& registers) { registers.pc.d16 += 1; }

    void XRI(Registers& registers) { registers.pc.d16 += 2; }
}
