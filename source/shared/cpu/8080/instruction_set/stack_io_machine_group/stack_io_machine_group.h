#ifndef EMULATOR_STACK_IO_MACHINE_GROUP_H
#define EMULATOR_STACK_IO_MACHINE_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace machine {
    void EI(Registers& registers);
    void DI(Registers& registers);
    void HLT(Registers& registers);

    void NOP(Registers& registers);
    void Unimplemented(Registers& registers);
}

namespace stack {
    void PUSH_B(Registers& registers);
    void PUSH_D(Registers& registers);
    void PUSH_H(Registers& registers);

    void PUSH_PSW(Registers& registers);

    void POP_B(Registers& registers);
    void POP_D(Registers& registers);
    void POP_H(Registers& registers);

    void POP_PSW(Registers& registers);

    void XTHL(Registers& registers);
    void SPHL(Registers& registers);
}

namespace io {
    void IN(Registers& registers);
    void OUT(Registers& registers);
}
#endif
