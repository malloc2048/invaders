#ifndef EMULATOR_STACK_IO_MACHINE_GROUP_H
#define EMULATOR_STACK_IO_MACHINE_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace machine {
    void EI(Regs& registers);
    void DI(Regs& registers);
    void HLT(Regs& registers);

    void NOP(Regs& registers);
    void Unimplemented(Regs& registers);
}

namespace stack {
    void PUSH_B(Regs& registers);
    void PUSH_D(Regs& registers);
    void PUSH_H(Regs& registers);

    void PUSH_PSW(Regs& registers);

    void POP_B(Regs& registers);
    void POP_D(Regs& registers);
    void POP_H(Regs& registers);

    void POP_PSW(Regs& registers);

    void XTHL(Regs& registers);
    void SPHL(Regs& registers);
}

namespace io {
    void IN(Regs& registers);
    void OUT(Regs& registers);
}
#endif
