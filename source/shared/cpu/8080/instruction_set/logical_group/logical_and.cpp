#include "logical_group.h"

namespace logical_and {
    void ANA_A(Registers& registers) { registers.pc.d16 += 1; }
    void ANA_B(Registers& registers) { registers.pc.d16 += 1; }
    void ANA_C(Registers& registers) { registers.pc.d16 += 1; }
    void ANA_D(Registers& registers) { registers.pc.d16 += 1; }
    void ANA_E(Registers& registers) { registers.pc.d16 += 1; }
    void ANA_H(Registers& registers) { registers.pc.d16 += 1; }
    void ANA_L(Registers& registers) { registers.pc.d16 += 1; }
    void ANA_M(Registers& registers) { registers.pc.d16 += 1; }

    void ANI(Registers& registers) { registers.pc.d16 += 2; }
}
