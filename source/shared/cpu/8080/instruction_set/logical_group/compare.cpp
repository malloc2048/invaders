#include "common/config.h"
#include "logical_group.h"
#include "common/utilities.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace compare {
    void CMP_A(Regs& registers) { machine::Unimplemented(registers); }
    void CMP_B(Regs& registers) { machine::Unimplemented(registers); }
    void CMP_C(Regs& registers) { machine::Unimplemented(registers); }
    void CMP_D(Regs& registers) { machine::Unimplemented(registers); }
    void CMP_E(Regs& registers) { machine::Unimplemented(registers); }
    void CMP_H(Regs& registers) { machine::Unimplemented(registers); }
    void CMP_L(Regs& registers) { machine::Unimplemented(registers); }
    void CMP_M(Regs& registers) { machine::Unimplemented(registers); }

    void CPI(Regs& registers) {
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
