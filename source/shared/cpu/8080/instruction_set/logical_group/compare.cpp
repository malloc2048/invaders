#include "common/config.h"
#include "logical_group.h"
#include "common/utilities.h"

namespace compare {
    void CMP_A(Registers& registers) { registers.pc.d16 += 1; }
    void CMP_B(Registers& registers) { registers.pc.d16 += 1; }
    void CMP_C(Registers& registers) { registers.pc.d16 += 1; }
    void CMP_D(Registers& registers) { registers.pc.d16 += 1; }
    void CMP_E(Registers& registers) { registers.pc.d16 += 1; }
    void CMP_H(Registers& registers) { registers.pc.d16 += 1; }
    void CMP_L(Registers& registers) { registers.pc.d16 += 1; }
    void CMP_M(Registers& registers) { registers.pc.d16 += 1; }

    void CPI(Registers& registers) {
        registers.psw.flags.z = registers.a == registers.memory[registers.pc.d16 + 1] ? 1 : 0;;
        registers.psw.flags.s = registers.a < registers.memory[registers.pc.d16 + 1] ? 1 : 0;
        registers.psw.flags.p = Parity(registers.a - registers.memory[registers.pc.d16 + 1], 8);
        registers.psw.flags.cy = registers.a < registers.memory[registers.pc.d16 + 1] ? 1 : 0;
        registers.psw.flags.ac = 0;
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "CPI %02x", registers.a);
    }
}
