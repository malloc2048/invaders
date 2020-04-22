#ifndef EMULATOR_LOGICAL_GROUP_H
#define EMULATOR_LOGICAL_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace logical_and {
    void ANA_A(Regs& registers);
    void ANA_B(Regs& registers);
    void ANA_C(Regs& registers);
    void ANA_D(Regs& registers);
    void ANA_E(Regs& registers);
    void ANA_H(Regs& registers);
    void ANA_L(Regs& registers);
    void ANA_M(Regs& registers);

    void ANI(Regs& registers);
}

namespace logical_or {
    void ORA_A(Regs& registers);
    void ORA_B(Regs& registers);
    void ORA_C(Regs& registers);
    void ORA_D(Regs& registers);
    void ORA_E(Regs& registers);
    void ORA_H(Regs& registers);
    void ORA_L(Regs& registers);
    void ORA_M(Regs& registers);

    void ORI(Regs& registers);
}

namespace logical_xor {
    void XRA(Regs& registers, uint8_t value, const char* instr);
    void XRA_A(Regs& registers);
    void XRA_B(Regs& registers);
    void XRA_C(Regs& registers);
    void XRA_D(Regs& registers);
    void XRA_E(Regs& registers);
    void XRA_H(Regs& registers);
    void XRA_L(Regs& registers);
    void XRA_M(Regs& registers);

    void XRI(Regs& registers);
}

namespace compare {
    void CMP_A(Regs& registers);
    void CMP_B(Regs& registers);
    void CMP_C(Regs& registers);
    void CMP_D(Regs& registers);
    void CMP_E(Regs& registers);
    void CMP_H(Regs& registers);
    void CMP_L(Regs& registers);
    void CMP_M(Regs& registers);

    void CPI(Regs& registers);
}

namespace rotate {
    void RLC(Regs& registers);
    void RRC(Regs& registers);
    void RAL(Regs& registers);
    void RAR(Regs& registers);
}

namespace compliment {
    void CMA(Regs& registers);
    void CMC(Regs& registers);
    void STC(Regs& registers);
}
#endif
