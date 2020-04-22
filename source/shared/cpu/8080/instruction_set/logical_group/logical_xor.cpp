#include "common/config.h"
#include "logical_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace logical_xor {
    void XRA(Regs& registers, uint8_t value, const char* instr) {
        registers.a ^= value;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %02x", instr, value);
    }

    void XRA_A(Regs& registers) { XRA(registers, registers.a, "XRA A"); }
    void XRA_B(Regs& registers) { XRA(registers, registers.bc.d8.highByte, "XRA B"); }
    void XRA_C(Regs& registers) { XRA(registers, registers.bc.d8.lowByte, "XRA C"); }
    void XRA_D(Regs& registers) { XRA(registers, registers.de.d8.highByte, "XRA D"); }
    void XRA_E(Regs& registers) { XRA(registers, registers.de.d8.lowByte, "XRA E"); }
    void XRA_H(Regs& registers) { XRA(registers, registers.hl.d8.highByte, "XRA H"); }
    void XRA_L(Regs& registers) { XRA(registers, registers.hl.d8.lowByte, "XRA L"); }
    void XRA_M(Regs& registers) { machine::Unimplemented(registers); }

    void XRI(Regs& registers) { machine::Unimplemented(registers); }
}
