#include "logical_group.h"
#include "common/config.h"
#include "common/utilities.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace logical_and {
    void ANA(Regs& registers, uint8_t value, const char* instr) {
        registers.a &= value;

        registers.psw.flags.z = registers.a == 0 ? 1 : 0;
        registers.psw.flags.s = (registers.a & 0x80u) > 0 ? 1 : 0;
        registers.psw.flags.p = Parity(registers.a, 8);
        registers.psw.flags.cy = 0;
        registers.psw.flags.ac = 0;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %02x", instr, value);
    }

    void ANA_A(Regs& registers) { ANA(registers, registers.a, "ANA A"); }
    void ANA_B(Regs& registers) { ANA(registers, registers.bc.d8.highByte, "ANA B"); }
    void ANA_C(Regs& registers) { ANA(registers, registers.bc.d8.lowByte, "ANA C"); }
    void ANA_D(Regs& registers) { ANA(registers, registers.bc.d8.highByte, "ANA D"); }
    void ANA_E(Regs& registers) { ANA(registers, registers.de.d8.lowByte, "ANA E"); }
    void ANA_H(Regs& registers) { ANA(registers, registers.bc.d8.highByte, "ANA H"); }
    void ANA_L(Regs& registers) { ANA(registers, registers.hl.d8.lowByte, "ANA L"); }
    void ANA_M(Regs& registers) { ANA(registers, registers.memory[registers.hl.d16], "ANA M"); }

    void ANI(Regs& registers) {
        registers.a &= registers.memory[registers.pc.d16 + 1];

        registers.psw.flags.z = registers.a == 0 ? 1 : 0;
        registers.psw.flags.s = (registers.a & 0x80u) > 0 ? 1 : 0;
        registers.psw.flags.p = Parity(registers.a, 8);
        registers.psw.flags.cy = 0;
        registers.psw.flags.ac = 0;
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "ANI %02x", registers.memory[registers.pc.d16 + 1]);
    }
}
