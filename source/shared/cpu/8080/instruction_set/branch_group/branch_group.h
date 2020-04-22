#ifndef EMULATOR_BRANCH_GROUP_H
#define EMULATOR_BRANCH_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace branch {
    void Jump(Regs& registers);
    void Call(Regs& registers);
    void Return(Regs& registers);
}

namespace jump {
    void JMP(Regs& registers);
    void JNZ(Regs& registers);
    void JZ(Regs& registers);
    void JNC(Regs& registers);
    void JC(Regs& registers);
    void JPO(Regs& registers);
    void JPE(Regs& registers);
    void JP(Regs& registers);
    void JM(Regs& registers);

    void PCHL(Regs& registers);
}

namespace call {
    void CALL(Regs& registers);
    void RET(Regs& registers);

    void CNZ(Regs& registers);
    void CZ(Regs& registers);
    void CNC(Regs& registers);
    void CC(Regs& registers);
    void CPO(Regs& registers);
    void CPE(Regs& registers);
    void CP(Regs& registers);
    void CM(Regs& registers);

    void RNZ(Regs& registers);
    void RZ(Regs& registers);
    void RNC(Regs& registers);
    void RC(Regs& registers);
    void RPO(Regs& registers);
    void RPE(Regs& registers);
    void RP(Regs& registers);
    void RM(Regs& registers);
}

namespace restart {
    void RST_0(Regs& registers);
    void RST_1(Regs& registers);
    void RST_2(Regs& registers);
    void RST_3(Regs& registers);
    void RST_4(Regs& registers);
    void RST_5(Regs& registers);
    void RST_6(Regs& registers);
    void RST_7(Regs& registers);
}
#endif
