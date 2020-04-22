#include "common/config.h"
#include "arithmetic_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace increment {
    void INR_A(Regs& registers) { machine::Unimplemented(registers); }
    void INR_B(Regs& registers) { machine::Unimplemented(registers); }
    void INR_C(Regs& registers) { machine::Unimplemented(registers); }
    void INR_D(Regs& registers) { machine::Unimplemented(registers); }
    void INR_E(Regs& registers) { machine::Unimplemented(registers); }
    void INR_H(Regs& registers) { machine::Unimplemented(registers); }
    void INR_L(Regs& registers) { machine::Unimplemented(registers); }
    void INR_M(Regs& registers) { machine::Unimplemented(registers); }

    void incrementPair(pair& pc, pair& regPair, const char* instr) {
        if(regPair.d8.lowByte == 0xff)
            regPair.d8.highByte += 1;
        regPair.d8.lowByte += 1;
        pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, regPair.d16);
    }

    void INX_B(Regs &registers) { incrementPair(registers.pc, registers.bc, "INX B"); }
    void INX_D(Regs &registers) { incrementPair(registers.pc, registers.de, "INX D"); }
    void INX_H(Regs &registers) { incrementPair(registers.pc, registers.hl, "INX H"); }
    void INX_SP(Regs &registers) { incrementPair(registers.pc, registers.sp, "INX SP"); }
}
