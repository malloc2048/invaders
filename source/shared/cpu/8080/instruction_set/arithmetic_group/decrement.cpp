#include "common/config.h"
#include "common/utilities.h"
#include "arithmetic_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace decrement {
    void decrement(Registers& registers, uint8_t* reg, const char* instr) {
        *reg -= 1;
        registers.pc.d16 += 1;

        registers.psw.flags.z = *reg == 0 ? 1 : 0;
        registers.psw.flags.s = *reg >= 0x80 ? 1 : 0;
        registers.psw.flags.p = Parity(*reg, 8);
        registers.psw.flags.ac = (*reg & 0x0fu) == 0x0fu ? 1 : 0;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %02x", instr, *reg);
    }

    void DCR_A(Registers& registers) { decrement(registers, &registers.a, "DCR A"); }
    void DCR_B(Registers& registers) { decrement(registers, &registers.a, "DCR B"); }
    void DCR_C(Registers& registers) { decrement(registers, &registers.a, "DCR C"); }
    void DCR_D(Registers& registers) { decrement(registers, &registers.a, "DCR D"); }
    void DCR_E(Registers& registers) { decrement(registers, &registers.a, "DCR E"); }
    void DCR_H(Registers& registers) { decrement(registers, &registers.a, "DCR H"); }
    void DCR_L(Registers& registers) { decrement(registers, &registers.a, "DCR L"); }
    void DCR_M(Registers& registers) { decrement(registers, &registers.a, "DCR M"); }

    void DCX_B(Registers &registers) { machine::Unimplemented(registers); }
    void DCX_D(Registers &registers) { machine::Unimplemented(registers); }
    void DCX_H(Registers &registers) { machine::Unimplemented(registers); }
    void DCX_SP(Registers &registers) { machine::Unimplemented(registers); }
}
