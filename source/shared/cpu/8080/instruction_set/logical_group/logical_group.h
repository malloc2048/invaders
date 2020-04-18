#ifndef EMULATOR_LOGICAL_GROUP_H
#define EMULATOR_LOGICAL_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace logical_and {
    void ANA_A(Registers& registers);
    void ANA_B(Registers& registers);
    void ANA_C(Registers& registers);
    void ANA_D(Registers& registers);
    void ANA_E(Registers& registers);
    void ANA_H(Registers& registers);
    void ANA_L(Registers& registers);
    void ANA_M(Registers& registers);

    void ANI(Registers& registers);
}

namespace logical_or {
    void ORA_A(Registers& registers);
    void ORA_B(Registers& registers);
    void ORA_C(Registers& registers);
    void ORA_D(Registers& registers);
    void ORA_E(Registers& registers);
    void ORA_H(Registers& registers);
    void ORA_L(Registers& registers);
    void ORA_M(Registers& registers);

    void ORI(Registers& registers);
}

namespace logical_xor {
    void XRA_A(Registers& registers);
    void XRA_B(Registers& registers);
    void XRA_C(Registers& registers);
    void XRA_D(Registers& registers);
    void XRA_E(Registers& registers);
    void XRA_H(Registers& registers);
    void XRA_L(Registers& registers);
    void XRA_M(Registers& registers);

    void XRI(Registers& registers);
}

namespace compare {
    void CMP_A(Registers& registers);
    void CMP_B(Registers& registers);
    void CMP_C(Registers& registers);
    void CMP_D(Registers& registers);
    void CMP_E(Registers& registers);
    void CMP_H(Registers& registers);
    void CMP_L(Registers& registers);
    void CMP_M(Registers& registers);

    void CPI(Registers& registers);
}

namespace rotate {
    void RLC(Registers& registers);
    void RRC(Registers& registers);
    void RAL(Registers& registers);
    void RAR(Registers& registers);
}

namespace compliment {
    void CMA(Registers& registers);
    void CMC(Registers& registers);
    void STC(Registers& registers);
}
#endif
