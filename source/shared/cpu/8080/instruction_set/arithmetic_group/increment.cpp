#include "common/config.h"
#include "arithmetic_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace increment {
    void INR_A(Registers& registers) { machine::Unimplemented(registers); }
    void INR_B(Registers& registers) { machine::Unimplemented(registers); }
    void INR_C(Registers& registers) { machine::Unimplemented(registers); }
    void INR_D(Registers& registers) { machine::Unimplemented(registers); }
    void INR_E(Registers& registers) { machine::Unimplemented(registers); }
    void INR_H(Registers& registers) { machine::Unimplemented(registers); }
    void INR_L(Registers& registers) { machine::Unimplemented(registers); }
    void INR_M(Registers& registers) { machine::Unimplemented(registers); }

    void incrementPair(pair& pc, pair& regPair, const char* instr) {
        if(regPair.d8.lowByte == 0xff)
            regPair.d8.highByte += 1;
        regPair.d8.lowByte += 1;
        pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, regPair.d16);
    }

    void INX_B(Registers &registers) { incrementPair(registers.pc, registers.bc, "INX B"); }
    void INX_D(Registers &registers) { incrementPair(registers.pc, registers.de, "INX D"); }
    void INX_H(Registers &registers) { incrementPair(registers.pc, registers.hl, "INX H"); }
    void INX_SP(Registers &registers) { incrementPair(registers.pc, registers.sp, "INX SP"); }
}
