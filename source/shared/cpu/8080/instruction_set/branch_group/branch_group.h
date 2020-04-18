#ifndef EMULATOR_BRANCH_GROUP_H
#define EMULATOR_BRANCH_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace branch {
    void Jump(Registers& registers);
    void Call(Registers& registers);
    void Return(Registers& registers);
}

namespace jump {
    void JMP(Registers& registers);
    void JNZ(Registers& registers);
    void JZ(Registers& registers);
    void JNC(Registers& registers);
    void JC(Registers& registers);
    void JPO(Registers& registers);
    void JPE(Registers& registers);
    void JP(Registers& registers);
    void JM(Registers& registers);

    void PCHL(Registers& registers);
}

namespace call {
    void CALL(Registers& registers);
    void RET(Registers& registers);

    void CNZ(Registers& registers);
    void CZ(Registers& registers);
    void CNC(Registers& registers);
    void CC(Registers& registers);
    void CPO(Registers& registers);
    void CPE(Registers& registers);
    void CP(Registers& registers);
    void CM(Registers& registers);

    void RNZ(Registers& registers);
    void RZ(Registers& registers);
    void RNC(Registers& registers);
    void RC(Registers& registers);
    void RPO(Registers& registers);
    void RPE(Registers& registers);
    void RP(Registers& registers);
    void RM(Registers& registers);
}

namespace restart {
    void RST_0(Registers& registers);
    void RST_1(Registers& registers);
    void RST_2(Registers& registers);
    void RST_3(Registers& registers);
    void RST_4(Registers& registers);
    void RST_5(Registers& registers);
    void RST_6(Registers& registers);
    void RST_7(Registers& registers);
}
#endif
