#include "arithmetic_group.h"

namespace subtraction {
    void SUB_A(Registers& registers) { registers.pc.d16 += 1; }
    void SUB_B(Registers& registers) { registers.pc.d16 += 1; }
    void SUB_C(Registers& registers) { registers.pc.d16 += 1; }
    void SUB_D(Registers& registers) { registers.pc.d16 += 1; }
    void SUB_E(Registers& registers) { registers.pc.d16 += 1; }
    void SUB_H(Registers& registers) { registers.pc.d16 += 1; }
    void SUB_L(Registers& registers) { registers.pc.d16 += 1; }
    void SUB_M(Registers& registers) { registers.pc.d16 += 1; }

    void SUI(Registers& registers) { registers.pc.d16 += 2; }
    void SBI(Registers& registers) { registers.pc.d16 += 2; }

    void SBB_A(Registers& registers) { registers.pc.d16 += 1; }
    void SBB_B(Registers& registers) { registers.pc.d16 += 1; }
    void SBB_C(Registers& registers) { registers.pc.d16 += 1; }
    void SBB_D(Registers& registers) { registers.pc.d16 += 1; }
    void SBB_E(Registers& registers) { registers.pc.d16 += 1; }
    void SBB_H(Registers& registers) { registers.pc.d16 += 1; }
    void SBB_L(Registers& registers) { registers.pc.d16 += 1; }
    void SBB_M(Registers& registers) { registers.pc.d16 += 1; }
}
