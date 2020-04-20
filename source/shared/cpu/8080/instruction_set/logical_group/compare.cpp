#include "common/config.h"
#include "logical_group.h"
#include "common/utilities.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace compare {
    void CMP_A(Registers& registers) { machine::Unimplemented(registers); }
    void CMP_B(Registers& registers) { machine::Unimplemented(registers); }
    void CMP_C(Registers& registers) { machine::Unimplemented(registers); }
    void CMP_D(Registers& registers) { machine::Unimplemented(registers); }
    void CMP_E(Registers& registers) { machine::Unimplemented(registers); }
    void CMP_H(Registers& registers) { machine::Unimplemented(registers); }
    void CMP_L(Registers& registers) { machine::Unimplemented(registers); }
    void CMP_M(Registers& registers) { machine::Unimplemented(registers); }

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
